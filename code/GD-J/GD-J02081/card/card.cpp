#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N=2e6+10,mod=998244353;
typedef pair<int,int> pii;
typedef long long ll;
/*

*/
int C,T=1;
int lst[N],cnt[N],res[N],n,m,a[N];
void mian(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],lst[a[i]]=i;
	for(int i=1;i<=n;i++)
		++cnt[i],res[a[i]]+=cnt[i],cnt[lst[a[i]]+1]+=cnt[i];
	for(int i=1;i<=m;i++) cout<<res[i]<<" ";
	return;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
//	cin>>C>>T;
	while(T--) mian();
	return 0;
}

