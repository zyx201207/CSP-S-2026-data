#include <bits/stdc++.h>
using namespace std;
#define F std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
int n,m,h[500005],nxt[500005],cnt[300005];
int main(void){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int i,j;
	map<int,int> mp,cnt;
	memset(nxt,-1,sizeof(nxt));
	cin>>n>>m;
	for(i=1;i<=n;++i){
		cin>>h[i];
		if(mp.count(h[i]))nxt[mp[h[i]]]=i;
		mp[h[i]]=i;
	}
	for(i=1;i<=n;++i)
		for(j=nxt[i];j!=-1;j=nxt[j])nxt[i]=j;
	for(i=1;i<=n;++i){
		for(j=i;j<=n;){
			if(nxt[j]!=-1)j=nxt[j];
			else cnt[h[j]]++,++j;
		}
	}
	for(i=1;i<=m;++i)cout<<cnt[i]<<" ";
	return 0;
}
