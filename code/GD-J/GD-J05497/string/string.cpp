#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e5+20;
struct word{
	char ch;
	ll x;
}p[N];
char s;
ll num=0;
ll l,r;
ll ans;
ll n;
signed main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].x>>s;
		p[i].ch=s;
	}
	l=1;
	r=n;
    while(l<=r){
    	if(p[l].ch!=p[r].ch){
    		if(p[l].x<p[r].x){
    			ans+=p[l].x;
    			p[r].x=p[r].x-p[l].x;
    			l++;
			}else if(p[r].x<p[l].x){
				ans+=p[r].x;
				p[l].x=p[l].x-p[r].x;
				r--;
			}else{
				ans+=p[r].x;
				l++;
				r--;
			}
		}else{
			if(p[l].x<p[r].x){
    			p[r].x=p[r].x-p[l].x;
    			l++;
			}else if(p[r].x<p[l].x){
				p[l].x=p[l].x-p[r].x;
				r--;
			}else{
				l++;
				r--;
			}
		}
	}
	cout<<ans<<"\n";
}
