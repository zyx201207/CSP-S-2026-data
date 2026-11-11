#include<bits/stdc++.h>
//#define DEBUG 1
//#define DLOG 1
//#ifdef DEBUG
//	#ifdef DLOG
//		#define log cerr
//	#else
//		#define log cout
//	#endif
//#else
//	#define DEBUG 0
//	#define DLOG 0
//	#define log 0&&cout
//#endif
//#define ifdb if(DEBUG)
using namespace std;
using ll=long long;
using i128=__int128;
const ll N=2e5;
ll n,m,a[N+10],out=LLONG_MAX;
vector<ll>jb[40];
bitset<40>b;
bitset<N+10>ans,as;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	freopen(".ky","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		b=a[i];
		for(ll j=0;j<=32;j++){
			if(b[j]){
				jb[j].push_back(i);
			}
		}
	}
	ans.set();
	for(ll j=32;j>=0;j--){
		if(jb[j].size()>=m){
			as.reset();
			for(auto&k:jb[j]){
				as[k]=1;
			}
			if((ans&as).count()>=m){
				ans&=as;
			}
		}
	}
	for(ll i=1;i<=n;i++){
		if(ans[i]){
			out&=a[i];
		}
	}
	cout<<out;
	return 0;
}
