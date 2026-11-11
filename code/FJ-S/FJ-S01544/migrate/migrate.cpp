#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,x[1000]={},jie[1000]={};
	cin>>c>>t;
	for(int a=1;a<=t;a++){
		jie[a]=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(j-i==3&&x[j]-x[i]==d+1){
					jie[a]++;
				}
			}
		}
	}
	for(int i=1;i<=t;i++){
		cout<<jie[i]<<'\n';
	}
	return 0;
}
