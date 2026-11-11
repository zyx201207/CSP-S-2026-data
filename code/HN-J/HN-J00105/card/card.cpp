//guan zhu Bzhan 开元玩游戏
//and luogu Kaikai23 
//我要被收录 
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
const ll N=5e5,M=3e5;
ll n,m,a[N+10],cnt[M+10],tag[M+10];
vector<ll>st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
//	freopen(".ky","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=0;i<n;i++){
		st.clear();
		st.push_back(0);
		for(ll j=i+1;j<=n;j++){
			if(tag[a[j]]){
				for(;tag[a[j]];){
					tag[st[st.size()-1]]=0;
					st.pop_back();
				}
			}
			tag[a[j]]=st.size();
			st.push_back(a[j]);
		}
		for(ll k=0;k<st.size();k++){
			tag[st[k]]=0;
			cnt[st[k]]++;
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
