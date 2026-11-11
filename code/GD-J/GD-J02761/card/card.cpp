#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=500005,maxm=300005;
ll n,m;
ll card[maxn];//存储点数
ll ed[maxn];//存储点数最后出现的位置
ll ans[maxn];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1; i<=n; i++) {
		cin>>card[i];
		ed[card[i]]=i;
	}
//	for(ll i=1; i<=n; i++) {
//		printf("%d**%d***%d\n",i,card[i],ed[card[i]]);
//	}
//	for(ll i=1; i<=n; i++) {
////		从第i张牌开始
//		ll p=i;
//		while(p<=n) {
//			while(ed[card[p]]==p)ans[card[p]]++,p++;
//			if(p>n)break;
//			p=ed[card[p]]+1;
//		}
//		cout<<i<<"**";
//		for(ll i=1; i<=m; i++) {
//			cout<<ans[i]<<" ";
//
//		}
//		cout<<endl;
//	}
	for(ll i=1; i<=m; i++) {
		cout<<1<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
