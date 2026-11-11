#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Endl "\n",void()
#define endl "\n"
#define End void()
namespace kong{bool st;}
const int N=2*1e5+7;
int n,m;
int maz[N][32],a[N];
bool vis[N];
deque<int> fz;
vector<int> x,y;
void fun(int x,int id){
	fz.clear();
	while(x){
		if(x&1) fz.push_front(1);
		else fz.push_front(0);
		x>>=1;
	}
	for(int i=31;i>=1;i--){
		if(fz.empty()) break;
		maz[id][i]=fz.back();
		fz.pop_back();
	}
	return;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],fun(a[i],i);
	for(int i=1;i<=31;i++){
		x.clear(),y.clear();
		for(int j=1;j<=n;j++){
			if(vis[j]==1) continue;
			if(maz[j][i]==1) x.push_back(j);
			else y.push_back(j);
		}
		if((int)x.size()<m) continue;
		else if((int)x.size()==m){
			int ans=a[x.back()];
			for(int u:x) ans&=a[u];
			return cout<<ans<<Endl;
		}else for(int u:y) vis[u]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(m==0) break;
		if(vis[i]==0){
			if(ans==0) ans=a[i],m--;
			else ans&=a[i],m--;
		}
	}
	return cout<<ans<<Endl;
}
namespace kong{bool ed;double MB(){return abs(&st-&ed)*1.0/1024/1024;}}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--) solve();
	cerr<<endl<<kong::MB()<<endl;
	return 0; 
} 
