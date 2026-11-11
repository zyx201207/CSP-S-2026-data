#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll c,t;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >>c>>t;
    while(t--){
    	ll n,k;
    	cin >>n>>k;
    	vector<ll> a[n+5];
    	int dis[n+5],color[n+5];
    	for(int i=1;i<n;i++){
    		ll u,v;
    		cin >>u>>v;
    		a[u].push_back(v);
    		a[v].push_back(u);
		}
//		ll cnt=0;
//		for(int i=1;i<=n;i++){
//			if(color[i]==0){
//				color[i]=cnt;
//				cnt++;
//			}
//		}
        cout <<k-1<<"\n"; 
	}
	return 0;
}
