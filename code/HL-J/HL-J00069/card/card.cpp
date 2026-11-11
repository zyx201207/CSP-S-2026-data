#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int res[N],ans[N];
int a[N],nxt[N],Now[N],sum[N];
int n,m;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		nxt[Now[a[i]]]=i;
		Now[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		res[i]=(nxt[i-1]==0?1:0)*sum[a[i-1]]+1;
		sum[a[i]]+=res[i];
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	}
	cout<<'\n';
	return 0;
}