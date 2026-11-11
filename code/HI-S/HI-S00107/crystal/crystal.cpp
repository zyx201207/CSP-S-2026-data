#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll maxn=1<<31;
ll n,m;
ll a[500005],ans,dc,k,mm=1;
map<ll,ll> mp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		int ny;
		cin>>ny;
		if(mp[ny]==0){
			a[mm]=ny;
			mm++;
			if(mm==3){
				dc=a[mm-1]-a[mm-2];
			}else if(mm>=3 && a[mm-1]-a[mm-2]!=dc){
				k=1;
			}
		}
		mp[ny]++;
	}
	
	sort(a+1,a+mm);
	if(k==0){
		
		ll kk=dc,cnt=1;
		while(m>=kk){
			m-=kk;
			cnt++;
			kk+=dc;
		}
		ans=cnt;
	}else{
		for(ll i=mm-1;i>=1;i--){
		ll cnt=mp[a[i]],h=m;
		map<ll,ll> pq; 
		for(ll j=i;j>=1;j--){
			if(a[i]==a[j] || pq[a[j]]==1)continue;
			if(a[i]-a[j]<=h){
				ll g=min(mp[a[j]],h/(a[i]-a[j]));
				h-=g*(a[i]-a[j]);
				cnt+=g;
				pq[a[j]]=1;
			}
			if(a[i]-a[j]>h)break;
		}
		ans=max(ans,cnt);
		}
	}
	
	cout<<ans;
	return 0;
}

