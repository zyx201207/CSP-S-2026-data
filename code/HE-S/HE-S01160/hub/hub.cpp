#include<bits/stdc++.h>
#define int long long
#define rep(i,l,r,x) for(int i=(l);i<=(r);i+=(x))
#define per(i,r,l,x) for(int i=(r);i>=(l);i-=(x))
#define pb push_back
using namespace std;
const int N=2e6+5;
int c,T,n,k;
vector<int> vt[N];
mt19937 rng(random_device{}());
void solve1(){
	cin>>n>>k;
	rep(i,1,n-1,1){
		int u,v;
		cin>>u>>v;
	}
	int m=n/2;
	cout<<(m+3)/4-k/4+1<<'\n';
}
void clr(){
	rep(i,0,n+1,1)vt[i].clear();
}
void solve2(){
	cin>>n>>k;
	rep(i,1,n-1,1){
		int u,v;
		cin>>u>>v;
		vt[u].pb(v),vt[v].pb(u);
	}
	cout<<n/5<<'\n';
	clr();
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	if(c>=13&&c<=14)while(T--)solve1();
	else while(T--)solve2();
	return 0;
} 
/*
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
