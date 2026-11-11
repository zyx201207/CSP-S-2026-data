#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m;
ll a[50010],ans[50010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for (ll i=1;i<=n;i++){
		bool t[50010];
		ll x[50010],x1[50010];
		memset(x,0,sizeof(x));
		memset(x1,0,sizeof(x1));
		memset(t,0,sizeof(t));
		for (ll j=i;j<=n;j++){
			if (x[a[j]] == 0){
				t[j] = 1;
				x1[a[j]] = j;
				x[a[j]] = 1;
			}else{
				for (ll k=x1[a[j]];k<j;k++){
					t[k] = 0;
				}
				x1[a[j]] = j;
				t[j] = 1;
			}
		}
		for (ll j=i;j<=n;j++){
			if (t[j] == 1){
				ans[a[j]]++;
			}
		}
	}
	for (ll i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}

