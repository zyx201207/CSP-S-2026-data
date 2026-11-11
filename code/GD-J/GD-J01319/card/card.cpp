#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define ref(i,a,b) for(int i=a;i>=b;--i)
#define rek(i,a,b) for(int i=a;i<b;++i)
#define Tie cin.tie(0)->sync_with_stdio(false)
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int T,n,m;
int a[N];
int p[M];
int ans[M];
struct Node
{
	int p,id;
}d[M];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	Tie,cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	ref(i,n,1)
	{
		if(!p[a[i]]) p[a[i]]=i,d[a[i]]={i,a[i]};
		ans[a[i]]++;
	}
	sort(d+1,d+m+1,[](Node x,Node y){return x.p<y.p;});
	rep(i,1,m)
	{
		if(d[i].p==n) continue;
		ans[a[d[i].p+1]]+=ans[d[i].id];
	}
	rep(i,1,m) cout<<ans[i]<<' ';
	return 0;
}//100pts