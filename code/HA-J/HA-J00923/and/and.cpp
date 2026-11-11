#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin,(x).end
#define fi first
#define se second
#define pb push_back
ll a[100009];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
    	cin>>a[i];
    }
    if(m==n){
        int ans=a[1];
        for(ll i=2;i<=n;i++){
        	ans=ans&a[i];
        	
        }
        cout<<ans;
        return 0;
    }
    else if(m==1){
    	sort(a+1,a+n+1);
    	cout<<a[n];
    	return 0;
    }
    else if(m==2){
    	int ans=-1;
    	for(ll i=1;i<=n;i++){
    		for(ll j=1;j<=n;j++){
    			if((j!=i)&&(a[i]&a[j])>ans){
    				ans=a[i]&a[j];
    			}
    		}
    	}
    	cout<<ans;
    	return 0;
    }
    	sort(a+1,a+n+1);
    	ll ans=a[n];
    	for(ll i=n-1;i>=n-m+1;i--){
    		ans=ans&a[i];
    	}
    	cout<<ans;
	return 0;
}























































































































































































