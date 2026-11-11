#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=5e5+7;
ll n,m,ans;
ll a[N];
ll mx=-1e18,mn=1e18;
bool f1=true;
bool f2=true;
priority_queue<ll,vector<ll>,greater<ll>> pq;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)	f1=false;
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
	}
	ll d=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=d){
			f2=false;
			break;
		}
	}
	if(f1){
		for(ll i=1;i<=n;i++){
			if(i*(i+1)/2>m){
				ans=i;
				break;
			}
			if(i==n)	ans=n;
		}
	}
	else if(f2){
		for(ll i=1;i<=n;i++){
			if((i*d+d)*i/2>m){
				ans=i;
				break;
			}
			if(i==n)	ans=n;
		}
	}
	else{
		for(ll k=mn;k<=mx;k++){
			while(!pq.empty()){
				pq.pop();
			}
			for(int i=1;i<=n;i++){
				if(a[i]<=k){
					pq.push(k-a[i]);
				}
			}
			ll w=m,cnt=0;
			while(!pq.empty()){
				if(w<pq.top()){
					break;
				}
				w-=pq.top();
				cnt++;
				pq.pop();
			}
			ans=max(ans,cnt);
		}
	}
	cout<<ans<<endl;
	return 0;
}

