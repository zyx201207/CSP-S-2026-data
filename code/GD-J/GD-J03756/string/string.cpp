#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Endl "\n",void()
#define endl "\n"
#define End void()
namespace kong{bool st;}
const int N=2*1e5+7;
int n;
struct node{
	ll cnt;
	char c;
	void put_in(){cin>>cnt>>c;}
}a[N];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) a[i].put_in();
	ll l=1,r=n,ans=0;
	while(l<=r){
		if(l==r) break;
		if(a[l].c==a[r].c&&a[l].cnt==a[r].cnt) l++,r--;
		else if(a[l].c==a[r].c){
			if(a[l].cnt<a[r].cnt) a[r].cnt-=a[l].cnt,l++;
			else a[l].cnt-=a[r].cnt,r--;
		}else{
			if(a[l].cnt<a[r].cnt) ans+=a[l].cnt,a[r].cnt-=a[l].cnt,l++;
			else ans+=a[r].cnt,a[l].cnt-=a[r].cnt,r--;
		}
	}
	return cout<<ans<<Endl;
}
namespace kong{bool ed;double MB(){return abs(&st-&ed)*1.0/1024/1024;}}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--) solve();
	cerr<<endl<<kong::MB()<<endl;
	return 0; 
} 
