//GZ-J00202 郭盛权 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll cnt,max_,now;
ll a[200005];
vector<ll> js;
bool nowp=false;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(ll i=0;i<n;++i)
		cin>>a[i];
	for(ll i=1;i<(1LL<<n);++i){
		for(ll j=0;j<=n;++j){
			if(i&(1LL<<j)){
				cnt++;
			}
		}
		if(cnt==m){
			for(ll j=0;j<n;++j){
				if(i&(1LL<<j)){
					js.push_back(j);	
				}
			}
			for(ll k:js){
				if(!nowp) now=a[k];
				nowp=true;
				now&=a[k];
			}
		}
		cnt=0,nowp=false;
		if(now>max_)max_=now;
		now=0;
		js={};
	}
	cout<<max_<<endl;
	
	return 0;
}
