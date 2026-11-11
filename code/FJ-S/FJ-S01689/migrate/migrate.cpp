#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6+10;
int c,t;
long long a[maxn];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		int ans=0;
		memset(a,0,sizeof(a));
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		int d2=a[2]-a[1];
		if(d<=2*d2){
			cout<<0<<"\n";
			continue;
		}
		int hnt;
		for(int i=1;i<=n;i++){
			if(d/(d2*i)*1.0<1){
				hnt=i-1;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(i+hnt-1<n){
				ans+=(hnt-2);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

