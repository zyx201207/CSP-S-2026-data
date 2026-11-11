#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N];bool bj[N];long long ans=0;
long long dfs(int x,long long v) {
	if(x==m) {
	ans=max(v,ans);
	return v;
	}
	long long cnt=0;
	for(int i=1;i<=n;++i) {
		if(!bj[i]) {
			bj[i]=1;
			cnt=max(dfs(x+1,v&a[i]),cnt);
			bj[i]=0;
		}
	}
	return cnt;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	if(n>2000) {
		sort(a+1,a+1+n);
	long long u=a[n];--m;
	for(int i=n-1;m>0;--i,--m)u&=a[i];
	cout<<u; 
	return 0;
	}
	for(int i=1;i<=n;++i)bj[i]=1,dfs(1,a[i]),bj[a[i]]=0;
	cout<<ans;
} 
