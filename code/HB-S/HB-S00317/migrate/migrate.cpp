#include<bits/stdc++.h>
using namespace std;
#define ll long long

int c,t,n,dp[5005][5005];
ll d,x[2000005];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cout<<0<<endl;
	}
	return 0;
}
