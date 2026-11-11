#include<bits/stdc++.h>
using ll = long long;
using namespace std;

constexpr int N = 5e5+7;

int n,maxn;

ll a[N],pre[N],m;

void solve(int p){
	int l = 1,r = p,ans = 1;
	while(l <= r){
		int mid = (l+r)>>1;
		if(pre[p-1]-pre[mid-1] + a[p]*(p-mid) <= m){
			r = mid-1;
			ans = mid;
		}else l = mid+1;
	}
	maxn = max(maxn,p - ans + 1);
}

int main(){freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 1;i<=n;i++){
		pre[i] = pre[i-1] - a[i];
	}
	for(int i = 1;i<=n;i++){
		solve(i);
	}
	cout<<maxn;
	return 0;
}
