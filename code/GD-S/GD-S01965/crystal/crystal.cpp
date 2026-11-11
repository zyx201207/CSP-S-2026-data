#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],maxn=-1e9;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int sum=0,ans=0;
		for(int j=i;j>=1&&sum+a[i]-a[j]<=m;j--)sum+=a[i]-a[j],ans++;
		maxn=max(maxn,ans);
	}
	cout<<maxn<<'\n';
	return 0;
}
