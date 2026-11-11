#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long dp[N],a[N],c,n,m,d,p,x,y,s,sx,t,e,mi=1e18;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(d!=2){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if((a[j]-a[i])%2==1)s++;
			}
		}
		cout<<s<<endl;
	}
	return 0;
} 
