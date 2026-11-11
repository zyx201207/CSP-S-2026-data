#include<bits/stdc++.h>
#define elif else if
//#define int long long
using namespace std;
const int N=5e5+100;
int n,m,a[N],las[N],sum[N],ans[N];
void input(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
}
void solve(){
	input();
	for(int i=1;i<=n;i++) las[a[i]]=i;
	for(int i=n;i>0;i--) sum[las[a[i]]]++;
	for(int i=1;i<=n;i++) if(i==las[a[i]]) ans[a[i]]=sum[i],sum[las[a[i+1]]]+=sum[i];
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
int main(){
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	solve();
	return 0;
}//Trick||Treat!
