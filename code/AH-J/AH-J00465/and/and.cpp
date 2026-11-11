#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200010],j[35],id[35][200010],maxd=0,ans=0;
struct side{
	ll num,iid;
};
vector<side> v;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
		cin>>a[i];
		ll t=a[i],d=0;
		v.push_back({a[i],i});
		while(t){
			if(t%2) id[d][i]=1,j[d]++;
			t/=2;
			d++;
			maxd=max(maxd,d-1);
		}
	}for(ll i=maxd;i>=0;i--){
		if(j[i]<m) continue;
		ll sumn=1;
		for(ll k=1;k<=i;k++) sumn*=2;
		ans+=sumn;
		vector<side> v2;
		for(ll k=0;k<ll(v.size());k++){
			if(id[i][v[k].iid]) v2.push_back({v[k].num,v[k].iid});
			else{
				ll t=v[k].num,d=0;
				while(t){
			        if(t%2) id[d][i]=0,j[d]--;
			        t/=2;
			        d++;
		        }
			}
		}v=v2;
	}cout<<ans;
    return 0;
}
