#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=2e6+10;

void solve();

ll c,t,n,d,a[maxn],nxt[maxn],lst[maxn],ans;
ll NXp[maxn],LSp[maxn];
ll NXcnt[maxn],LScnt[maxn];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}

void solve(){
	ans=0;
	for(int i=1;i<=n;i++)
		lst[i]=nxt[i]=LScnt[i]=NXcnt[i]=0;//NXp[i]=LSp[i]=1;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		lst[i]=lower_bound(a+1,a+i,a[i]-d)-a;
		if(lst[i]<i)LScnt[lst[i]]++,LSp[i]=LSp[lst[i]]+1;;
		nxt[i]=upper_bound(a+i+2,a+n+1,a[i]+d)-a-1;
		if(nxt[i]>i)NXcnt[nxt[i]]++;
	}for(int i=n;i>=1;i--){
		if(nxt[i]>i&&nxt[i]<=n)NXp[i]=NXp[nxt[i]]+1;
	}
//	for(int i=1;i<=n;i++)cout<<lst[i]<<" \n"[i==n];
//	for(int i=1;i<=n;i++)cout<<nxt[i]<<" \n"[i==n];
//	for(int i=1;i<=n;i++)cout<<LSp[i]<<" \n"[i==n];
//	for(int i=1;i<=n;i++)cout<<NXp[i]<<" \n"[i==n];

	for(int i=1;i<n;i++){
		ll u=i,v=i+1;
		if(nxt[u]==v||lst[v]==u)continue;
		if(lst[nxt[u]]!=u||nxt[lst[v]]!=v)continue;
		ans+=(NXcnt[lst[v]]+1)*(LScnt[nxt[u]]+1);
//		cout<<u<<' '<<v<<endl;
	}cout<<ans<<endl;
}/*
0 1
6 2
-4 -3 -2 -1 3 6

0 1
5 2
1 2 3 4 5

*/
