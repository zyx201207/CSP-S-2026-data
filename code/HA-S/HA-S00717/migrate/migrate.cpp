#include<bits/stdc++.h>
using namespace std;
int a[200001],tin,minx;
void dfs(int x,int z,int l,int b){
	if(x==z){
		if(b<minx){
			tin=1;
			minx=b;
		}else if(b==minx){
			tin++;
		}return;
	}for(int i=1;i<=l;i++)
		for(int j=x;j<=z;j++)
			if(a[x]+i==a[j])
				dfs(j,z,l,b+1);	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d,ans=0;
		cin>>n>>d;
		for(int j=1;j<=20001;j++) a[j]=0;
		for(int j=1;j<=n;j++) cin>>a[j];
		for(int j=1;j<n;j++)
			for(int k=j+1;k<=n;k++){
				tin=0;minx=10086;
				dfs(j,k,d,0);
				if(tin==2) ans++;
			}cout<<ans<<endl;
	}return 0;
}
