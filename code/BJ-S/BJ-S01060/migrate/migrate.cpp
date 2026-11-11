#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
ll c,t,n,m,a[maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		ll tmp=a[2]-a[1],mx=m/tmp,ans=0;
		for(int i=1;i+mx<=n;i++){
			ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
