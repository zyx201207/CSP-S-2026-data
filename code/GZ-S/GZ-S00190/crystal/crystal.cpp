//GZ-S00190贵阳市第三中学王上清 
#include<bits/stdc++.h>
#define ll long long 
#define pll pair<ll,ll>
using namespace std;
ll n,m,cnt;
void ji(){
	cin>>n>>m;
	ll z=m;
	vector<ll>a(n+1);
	vector<pll>b(n+1);
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.end());
	for(ll i=1;i<=n;i++){
		b[i].first=a[i];
	}
	for(ll i=1;i<=n;i++){
        a[i]+=a[i-1];
	}
	ll l=1,r=n;
	vector<ll>ans(41);
	for(ll i=1;i<=40;i++){
		m=z;
		ll mid=(l+r)/2;
		ll cnt=a[r];
		cnt/=r;
		priority_queue<pll>k;
		for(ll j=1;j<=r;j++){
			b[j].second=cnt-b[j].first;
			k.push({(b[j].second),b[j].first});
		}
		for(ll j=1;j<=r;j++){
			if((cnt-k.top().second)<0)break;
			if(m-(cnt-k.top().second)>=0){
				m-=(cnt-k.top().second);
				ans[i]++;
				k.pop();
			}	
			else{
				break;
			}
		}
		if(ans[i]>=ans[i-1]){
			if(ans[i]>mid){
				l=mid+1;
			}
			else{
				r=mid-1;				
			}
		}
		else{
			cout<<ans[j]<<endl;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int t=1;
	//cin>>t;
	while(t--){
		ji();
		
	}
	return 0;
} 
