#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll c,t;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >>c>>t;
    while(t--){
    	int n;
    	ll d;
    	cin >>n>>d;
    	vector<ll> a(n,0),can(n+1,0);
    	for(int i=0;i<n;i++){
    		cin >>a[i];
    		//sum[i]=1;
    		//dis[i]=INT_MAX;
		}
		//sort(a+1,a+1+n);
		//ll l=1;
//		for(int i=1;i<=n;i++){
//			while(l<=n&&a[l]+d<a[i]){
//				l++;
//			}
//		}
        ll ans=0;
        for(int i=0;i<n;i++){
        	can[i]=lower_bound(a.begin(),a.end(),a[i]-d)-a.begin();
		}
        for(int q=0;q<n;q++){
        	vector<ll> dis(n+1,INT_MAX),sum(n+1,1);
        	dis[q]=0;
        	for(int i=q+1;i<n;i++){	
				for(int j=can[i];j<=i-1;j++){
					if(dis[j]+1<dis[i]){
						dis[i]=dis[j]+1;
						sum[i]=sum[j];
					}else if(dis[j]+1==dis[i]){
						sum[i]=sum[i]+1;
					}
				}
				if(sum[i]==2){
					ans++;
				}
			}
		}
		cout <<ans<<"\n";
	}
	return 0;
}
