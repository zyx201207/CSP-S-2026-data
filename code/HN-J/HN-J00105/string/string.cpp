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
ll n,ans=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	freopen(".ky","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	{
		char c;
		ll a;
		for(ll i=1;i<=n;i++){
			cin>>a>>c;
			for(ll i=1;i<=a;i++){
				s.push_back(c);
			}
		}
	}
	for(ll l=0,r=s.size()-1;l<r;l++,r--){
		if(s[l]!=s[r]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
