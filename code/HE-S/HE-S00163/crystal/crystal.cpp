#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",std.out);
	ll n,m,ans,x;
	cin >> n >> m;
	ll a[n],b[n];

	for(ll i = 1; i <= n; i++){
		cin >> a[i]; 
		b[a[i]]++;
	}
	for(ll i = 1; i <= n; i++){
		ans = max(ans,b[i]);
		if(ans == b[i]){
			x = i;
		}
	}
	
	if(m == 0){
		cout << ans;
	}
	sort(a+1,a+n+1);
	while(m == 0){
		for (ll i = 1; i <= n; i++){
    	    for (ll j = 1; j <= n; j++){
    		    if(abs(a[i] - x) > abs(a[j] - x)){
    			    m -= abs(a[j] - x);
    			    ans++;
			}
    		    else{
    			    m -= abs(a[i] - x);
    			    ans++;
			    }
		    }
	    }
	}
	cout << ans;
	
	
	
	
	
	return 0;
}
