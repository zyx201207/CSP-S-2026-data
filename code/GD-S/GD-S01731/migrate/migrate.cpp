#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,n,d,T,x[N]; 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(c>=11 && c<=12){
			int y=d/(x[2]-x[1]);
			for(int i=1;i<=n-y;i++){
				ans+=max(0ll,(n-i+1)-y-(n-i)/y);
			}
			cout<<ans<<'\n';
		}
		
	}
	return 0;
}
/*
T3
神秘计数题 
*/
