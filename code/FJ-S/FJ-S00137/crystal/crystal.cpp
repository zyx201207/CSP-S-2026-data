#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+5;
long long n,m,ans=-2e9;
long long a[MAXN];
long long b[3][MAXN];
void dfs(int m1){
	if(m1==0){
		for(int i=1;i<=n;i++){
			b[1][i]=0;
			b[2][i]=0;
		}
		for(int i=1;i<=n;i++){
			if(a[i]<0)b[1][-a[i]]++;
			if(a[i]>=0)b[2][a[i]]++;
		}
		for(int i=1;i<=n;i++){
			ans = max(b[2][i],ans);
			ans = max(b[1][i],ans);
		}
		return;
	}
	for(int i=1;i<=n;i++){
		a[i]++;
		dfs(m1-1);
		a[i]--;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	dfs(m);
	cout << ans << "\n";
	return 0;
}
