#include<bits/stdc++.h>
#define LL long long
#define P(i,s,t) for(int i=s;i<=t;++i)
#define S(i,s,t) for(int i=s;i>=t;--i)
using namespace std;
const int N=5e5+55;
int n,m;
int a[N],en[N],dis[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	P(i,1,n) cin>>a[i],en[a[i]]=i;
	P(i,1,n){
		ans[a[i]]+=++dis[i];
		dis[en[a[i]]+1]+=dis[i];
	}
	P(i,1,m-1) cout<<ans[i]<<' ';
	cout<<ans[m];
	
	return 0;
}
