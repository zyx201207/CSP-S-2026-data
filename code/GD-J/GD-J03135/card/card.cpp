#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,P=0x3f3f3f3f3f3f3f3f;
int n,m,a[N],cnt[N],vis[N],ans[N];
struct node{
	int l,r;
}p[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)vis[j]=cnt[j]=0;
		for(int j=i;j<=n;j++){
			if(vis[a[j]])for(int k=vis[a[j]];k<j;k++)cnt[a[k]]--;
			cnt[a[j]]++;
			vis[a[j]]=j;
		}
		for(int j=1;j<=m;j++)if(cnt[j])ans[j]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}

