#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m,a[N],anss,maxx;
map<int,int> mp;
void dfs(int x,int c,int sum){
	if(c==m){
		anss=max(anss,sum);
		return;
	}
	if(x==n) return;
	dfs(x+1,c+1,sum&a[x+1]);
	dfs(x+1,c,sum);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout << ans;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout << ans;
		return 0;
	}
	if(m==2){
		int ans=0;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	if(n<=20){
		for(int i=1;i<=n;i++)
			dfs(i,1,a[i]);
		cout << anss;
		return 0;
	}
	if(maxx>4){
		for(int i=1;i<=n;i++){
			mp[a[i]]++;
		}
		if(mp[3]>=m) cout << 3;
		else if(mp[2]+mp[3]>=m) cout << 2;
		else if(mp[3]+mp[1]>=m) cout << 1;
		else cout << 0;
		return 0;
	}
	sort(a+1,a+n+1);
	cout << a[n-m+1];
	return 0;
}


