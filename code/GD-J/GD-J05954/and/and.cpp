#include<bits/stdc++.h> 
using namespace std;
int a[10005],b[10005],c[10005];
void o(int n,int a[],int b[]){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				int i0=1;
				c[i0]=a[i]&b[i];
				i0++;
			}
		}
	}
}
bool cmp(int y,int u){
	if(y>u)return 1;
	return 0;
}
int main(){
	freopen("and.in.txt","r",stdin);
	freopen("and.out.txt","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a1;
		cin>>a1;
		a[i]=a1;
		b[i]=a1;
	}
	if(m%2==0){
		for(int i=1;i<=m/2;i++){
		    o(n,a[],b[]);
		    o(n,b[],c[]);
	    }
	    sort(a+1,a+10005,cmp);
	    cout<<a[0];
	}else{
		for(int i=1;i<=(m-1)/2;i++){
		    o(n,a[],b[]);
		    o(n,b[],c[]);
	    }o(n,a[],b[]);
	    sort(c+1,c+10005,cmp);
	    cout<<c[0];
	}
}
