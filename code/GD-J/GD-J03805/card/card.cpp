#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],last[300005],cnt[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int z=1;z<=n;z++){
		cin>>a[z];
		last[a[z]]=z;
	}
	for(int z=1;z<=n;z++){
		cnt[z]++;
		ans[a[z]]+=cnt[z];
		cnt[last[a[z]]+1]+=cnt[z];
	}
	for(int z=1;z<=m;z++)cout<<ans[z]<<" ";
	return 0;
}
