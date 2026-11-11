#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,ans;
ll m,a[500010],cnt[500010];
bool check(int x,int b){
	ll sum = abs((a[x] * (ll)(x - b)) - (cnt[x - 1] - cnt[b - 1]));
	return sum <= m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for (int i = 1;i <= n;i++)
		cin>>a[i];
	sort(a + 1,a + 1 + n);
	for (int i = 1;i <= n;i++)
		cnt[i] = cnt[i - 1] + a[i];
	for (int i = 2;i <= n;i++){
		int l = 1,r = i;
		while (l < r){
			int mid = (l + r) / 2;
			if (check(i,mid)) r = mid;
			else l = mid + 1;
		}
		ans = max(ans,i - l + 1);
	}
	cout<<ans;
	return 0;
}

