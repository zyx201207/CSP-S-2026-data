#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,Mod=998244353;
int a[N],b[N],fst[N],c[N],qwq[N],bel[N],ans[N];
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		b[i]=a[n-i+1];
	int awa=0;
	for(int i=1;i<=n;i++){
		if(fst[b[i]]==0){
			awa++;
			fst[b[i]]=awa;
			qwq[awa]=i;
			c[awa]++;
			bel[i]=awa;
		}
		else{
			c[fst[b[i]]]++;
			bel[i]=fst[b[i]];
		}
	}
	for(int i=awa;i>=1;i--){
		ans[b[qwq[i]]]+=c[i];
		c[bel[qwq[i]-1]]+=c[i];
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t=1;
	while(t--)
		solve();
	return 0;
}
