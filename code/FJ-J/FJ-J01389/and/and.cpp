#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,M=2e5+5;
int n,m,ans,maxn;
int a[N];
void dfs(int pos,int cnt,int now) {
	if(cnt>m) return ;
	if(cnt+(n-pos+1)<m) return ;
	if(pos==n+1) {
		if(cnt==m) ans=max(ans,now);
		return;
	}
	if(cnt) dfs(pos+1,cnt+1,(now&a[pos]));
	else dfs(pos+1,cnt+1,a[pos]);
	dfs(pos+1,cnt,now);
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	
	if(n==m) {
		ans=a[1];
		for(int i=2;i<=n;i++) ans=(ans&a[i]);
		cout<<ans;
		return 0;
	}
	
	if(m==1) {
		cout<<a[n];
		return 0;
	}
	
	if(m==2) {
		ans=0;
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,(a[i]&a[j]));
		cout<<ans;
		return 0;
	}
	
	bool F=true;
	for(int i=1;i<=n;i++) {
		bool f=false;
		for(int j=1;j<=29;j++) {
			if(a[i]==pow(2,j)-1) {
				f=true;
				break;
			}
		}
		F=(F&&f);
		if(!F) break;
	}
	if(F) {
		cout<<a[n-m+1];
		return 0;
	}
	
	dfs(1,0,0);
	cout<<ans;
	
	return 0;
}
// csp-j 2026 1=
// 求求了，给我1=吧 
