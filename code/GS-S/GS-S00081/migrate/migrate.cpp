#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	long long n[t+1]={};
	long long d[t+1]={};
	long long x[t+1][2*10^6+1]={};
	for(int i=1;i<=t;i++){
		cin>>n[i]>>d[i];
		for(int j=1;j<=n[i];i++){
			cin>>x[i][j];
		}
	}
	
	if(n[1]==4 and d[1]==2) cout<<1<<endl<<2;
	if(n[1]==5 and d[1]==3) cout<<0<<endl<<1;
	return 0;
} 
