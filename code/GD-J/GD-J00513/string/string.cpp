#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
int n,cnt[maxn];
char a[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++)	
		cin >> cnt[i] >> a[i];
	int l=1,r=n;
	ll ansl=0,ansr=0;
	while (l<r){
		ll delta=min(cnt[l],cnt[r]);
		if (a[l]!=a[r]){
			ansl+=delta;
			ansr+=delta;
		}
		cnt[l]-=delta;
		cnt[r]-=delta;
		if (cnt[l]<=0)
			l++;
		if (cnt[r]<=0)
			r--;
	}
	cout << min(ansl,ansr);
	return 0;
}
