#include<bits/stdc++.h>
#define N 500005
#define ll long long
using namespace std;
int n;
ll m,dat[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> dat[i];
	}
	sort(dat + 1,dat + n + 1);
	for(int i = 1;i <= n;i ++){
		sum[i] = sum[i - 1] + dat[i];
	}
	int maxx = 0;
	for(int i = 1;i <= n;i ++){
		int l = 1,r = i,mid = 0,ans = 0;
		while(l <= r){
			mid = (l + r) >> 1;
			if(1ll * (i - mid + 1) * dat[i] - (sum[i] - sum[mid - 1]) <= m){
				ans = mid;
				r = mid - 1;
			}else{
				l = mid + 1;
			}
		}
		maxx = max(maxx,i - ans + 1);
	}
	cout << maxx;
	return 0;
}

