#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005];
int cnt,ans;
bool cmp(long long x,long long y){
	return x > y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1 ,a+n+1 ,cmp);
	for(int i = 1;i <= n;i++){
		int t = m;
		cnt = 1;
		for(int j = 1;j <= n;j++){
			if(i == j){
				continue;
			}
			if(a[i] > a[j]){
				if(t >= a[i] - a[j]){
					t -= (a[i] - a[j]);
					cnt++;
				}
			}
		}
		ans = max(ans ,cnt);
	}
	cout << ans;
	
	return 0;
}
