#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
typedef long long ll;
ll n,m,ans=-1919180;
ll a[maxn],q[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		ll res=0,cnt=0; 
		if (a[i]==a[i+1])
			continue;
		for (int j=i;j>=1;j--){
			cnt+=(a[i]-a[j]);
			if (cnt>m)
				break;
			res++;
		}
		cout << res << '\n';
		ans=max(ans,res);
	}
	cout << ans;
	return 0;
}
//Oct31==Dec25?
