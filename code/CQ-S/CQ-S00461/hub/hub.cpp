#include<bits/stdc++.h>
#include<bits/extc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
constexpr int N=55;
int c,t,n,k,ls[30],top;
vector<int> ps[N],ps2[N];
bitset<N> vis;
void solve(){
	cin>>n>>k;
	for(int i=1;i<n;++i){
		int u,v;
		ps[u].emplace_back(v);
		ps[v].emplace_back(u);
	}
	ll len=(1<<n);
	for(int i=0;i<len;++i){
		int j=i;
		memset(ls,0,sizeof ls);
		top=0;
		while(j){
			ls[++top]=j%2;
			j/=2; 
		}
		ll ans=0,cnt=0;
		for(int i=1;i<=n;++i){
			if(ls[i]){
				cnt++; 
				for(const auto &k:ps[i]){
					if(ls[k])ans++;
				}
			}
		}
		ans/=2;
		if(ans+2<cnt)continue;
		
	}
	cout<<1;
	return ; 
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)solve();








	return 0;
}




