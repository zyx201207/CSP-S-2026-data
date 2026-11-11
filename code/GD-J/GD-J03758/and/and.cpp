#include <bits/stdc++.h>
using namespace std;

const int maxn=2*1e5+5;
int n,m,a[maxn],ans;
int vis[maxn],change[maxn];

void solve1(int c,int s){
	if(c>m){
		int cnt=change[1];
		for(int i=2;i<=m;i++)	cnt=cnt&change[i];
		ans=max(ans,cnt);
		return;
	}
	for(int i=s;i<=n;i++){
		if(vis[i]==1)	continue;
		vis[i]=1;
		change[c]=a[i];
		solve1(c+1,i+1);
		vis[i]=0;
		change[c]=0;
	}
	return;
} 
void solve2(){
	sort(a+1,a+n+1);
	int e=n-m+1,cnt=a[n];
	for(int i=n-1;i>=e;i--)	cnt=cnt&a[i];
	ans=cnt;
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	if(n<=2000)	solve1(1,1);
	else if(n>2000&&m==n-1)	solve2(); 
	cout<<ans<<'\n';
	return 0;
} 
