#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t,ans;
	cin>>c>>t;
	long long bei;
		while(t--){
			bei=0;
			int n;
			long long d;
			cin>>n>>d;
			if(n<=3){
				cout<<0;
				continue;
			}
			int xx,xxx;
			cin>>xx>>xxx;
			long long cha=xxx-xx;
				long long x;
			for(int i=3;i<=n;i++){
			
				cin>>x;
			}
				if(cha*2>d){
					cout<<0;
				}else if(cha*2==d){
					ans=(n-3);
					cout<<ans;
				}else{
					bei=d/cha;
					ans=(n+2-2*bei)*(bei-2);
					cout<<ans;
			}
		}
	return 0;
}
