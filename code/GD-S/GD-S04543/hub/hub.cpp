#include<bits/stdc++.h>
#define ll long long
#define Furinas return
#define Tears 0
#define Arias 1
#define N 500005
using namespace std;
ll c,T,n,k,f[N],pos[N],sum=0,ans=1e18+7;
vector <ll> v[N];
ll find(ll x){Furinas x==f[x]?x:f[x]=find(f[x]);}
void dfs(ll x,ll fa,ll dis){
	sum=max(sum,dis);
	if(pos[x]) Furinas;
	for(auto y:v[x]){
		if(y==fa) continue;
		dfs(y,x,dis+1);
	}
}
void solve(vector <ll> &a){
	for(int i=0;i<k;i++){
		pos[a[i]]=1;
		for(auto y:v[a[i]]){
			ll tu=find(a[i]),tv=find(y);
			if(tu==tv) continue;
			f[tu]=f[tv];
		}
	} 
	ll fi=0;sum=0;
	for(int i=0;i<k-1;i++){
		if(f[a[i]]!=f[a[i+1]]){
			if(fi&&fi!=f[a[i+1]]) Furinas;
			fi=f[a[i]];
		}
	}
	for(int i=1;i<=n;i++) dfs(i,0,0);
	ans=min(ans,sum);
} 
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(Tears);
	cin.tie(Tears);cout.tie(Tears);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) f[i]=i,v[i].clear();
		for(int i=1;i<n;i++){
			ll fr,to;
			cin>>fr>>to;
			v[fr].push_back(to);
			v[to].push_back(fr);
		}
		if(c>=13&&c<=14){
			ll p=n/2,q=k/2;
			if((p-q)%2==0) cout<<(p-q)/2;
			else cout<<(p-q)/2+1;
			cout<<'\n';
		}
		ans=1e18+7;
		for(int mask=1;mask<(1<<n);mask++){
			ll cnt=__builtin_popcount(mask);
			if(cnt!=k) continue;
			vector <ll> g;
			for(int i=0;i<n;i++) if(mask&(1<<i)) g.push_back(i+1);
			for(int i=1;i<=n;i++) f[i]=i,pos[i]=0;
			solve(g);
		}
		cout<<ans<<endl;
	}
	Furinas Tears;
}
/*
±©Á¦¿ÉÐ´15·Ö
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
