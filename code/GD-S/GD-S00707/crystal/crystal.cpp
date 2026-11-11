#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005];
bool pf=1;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	int cha=a[2]-a[1];
	for (int i=3;i<=n;i++){
		if (a[i]-a[i-1]!=cha){
			pf=0;
		}
	}
	if (pf){
		int sum=0,cnt=0;
		while(sum<=m){
			cnt++;
			sum+=cha*cnt;
		}
		cout << cnt;
	}else{
		sort(a+1,a+n+1);
		bool flg=1;
		int maxn=-2e12;
		for (int i=1;i<=n && flg;i++){
			int tmp=m;
			for (int j=1;j<i;j++){
				if (tmp-(a[i]-a[j])<0){
					flg=0;
					break;
				}else{
					tmp-=(a[i]-a[j]);
				}
			}
			if (flg) maxn=i;
		}
		cout << maxn;
	}
	return 0;
}
