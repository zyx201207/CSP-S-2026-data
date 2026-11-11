#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int N = 1e6+5;
ll n;
ll hn[N];
char ch[N];
ll zj=0;
ll sum=0;
set<ll>b[N];
set<ll>maxn[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>hn[i]>>ch[i];
		b[ch[i]].insert(hn[i]);
	}
	
	ll k=1;
	ll ans=0;
	if(n%2!=0){
		zj=n/2+1;
		for(ll i=zj;i<=n;i++){
			if(ch[i]!=ch[zj-k])ans++;
		}
	}
	else {
	    zj=n/2;
	    k=0;
		for(int i=zj;i<=n;i++){
			if(ch[i]!=ch[zj+k]){
				ans++;
			}
		}	
	}
	cout<<ans;
	return 0;
}
