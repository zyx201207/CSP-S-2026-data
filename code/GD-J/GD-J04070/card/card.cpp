#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
using namespace std;
//#define getc() (uu==vv&&(vv=(uu=In)+fread(In,1,1<<15,stdin),uu==vv)?EOF:*uu++)
//template<class T>
//void R(T &x){
//	char c=getc();x=0;bool f=0;
//	for(;!isdigit(c);f|=(c=='-'),c=getc());
//	for(;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=getc());
//	f&&(x=-x);
//}
using ll = long long;
const int N=5e5+5;
int n,m,a[N],cnt[N],p[N],d[N],ans[N];
vector<int>ve[N];queue<int>q;
void solve(){
	cin>>n>>m;
	rep(i,1,n)cin>>a[i],p[a[i]]&&(ve[p[a[i]]].push_back(i),++d[i]),p[a[i]]=i;
	rep(i,1,m)if(p[i]&&p[i]^n)ve[p[i]].push_back(p[i]+1),++d[p[i]+1];
	rep(i,1,n)if(!d[i])q.push(i);
	while(!q.empty()){
		int u=q.front();q.pop();cnt[u]++;
		for(auto v:ve[u])cnt[v]+=cnt[u],(!--d[v])&&(q.push(v),1);
	}per(i,n,1)if(!ans[a[i]])ans[a[i]]=cnt[i];
	rep(i,1,m)cout<<ans[i]<<" ";
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
//	freopen("a.in","r",stdin);
//	freopen("a1.out","w",stdout);
	solve();
	return 0;
} 
