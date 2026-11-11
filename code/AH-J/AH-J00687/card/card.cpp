#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,x,a[111000],ss,ans[111000],cnt;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=0;i<n;i++){
		vector<ll> t,aw;
		ss++;
		cnt=0;
		for(ll j=i+1;j<=n;j++){
			t.push_back(a[j]);
			for(ll k=0;k<t.size();k++){
				if(t[k]!=a[j]){
					aw.push_back(t[k]);
				}
				else if(t[k]==a[j])break;
			}
		}
		if(ss<=m){
			for(ll j=0;j<aw.size();j++){
			    if(aw[j]==ss)cnt++;
		    }
		    ans[ss]=cnt;
		}
	}
	for(ll i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
