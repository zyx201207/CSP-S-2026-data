#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],lst[N],pos[N];
int ans[N],f[N],cnt[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) pos[a[i]]=1e9,cnt[a[i]]++;
	for(int i=n;i>=1;i--){
		if(pos[a[i]]==1e9) pos[a[i]]=i;
		lst[i]=pos[a[i]];
	}
	for(int i=1;i<=n;i++){
		if(f[a[i]]) continue;
		f[a[i]]=1;
		int now=i;
		while(now<=n){
			ans[a[now]]+=cnt[a[i]];
			now=lst[now]+1;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}

