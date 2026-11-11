#include<iostream>
using namespace std;
int max_=0;
int a[100005],x[100005];
void w(int s,int p,int l[],int g,int u,int v[]){
	if(s==1){
		int y=l[p];
		for(int z=2;z<=u;z++){
			y=y&v[z];
	}
	max_=max(max_,y);
	}else{
		v[s]=l[p];
		for(int j=p+1;j<=g-s+2;j++){
			w(s-1,j,l,g,u,v);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m+1;i++){
		w(m,i,a,n,m,x);
	}
	cout<<max_;
	return 0;
}
