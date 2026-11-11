#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e+6;
long long c,t,x[MAXN],d,sum,num;
bool f;
void fd(int u,int v,int k){
	if(x[v]-x[u]<=d){
		k++;
		if(num==0) num=k;
		else if(num==k){
			f=true;
		}
		else if(num>k){
			f=false;
			num=k;
		}
		return ;
	}
	for(int i=u+1;i<=v;i++){
		if(x[i]-x[u]<=d) fd(i,v,k+1); 
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		long long n;
		sum=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
			long long t=j-3;
			while(t>=1){
				num=0;
				fd(t,j,0);
				if(f) sum++;
				f=false;
				t--;
			}
		}
		cout<<sum<<endl;
	}
} 
