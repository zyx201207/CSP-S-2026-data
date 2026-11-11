#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
ll a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin >> n;
    for(ll i=1;i<=n;i++){
    	cin >> a[i] >> c[i];
	}
	if(n<=1){
		cout << 0;
	}else if(n<=2){
		if(c[1]==c[2])cout << 0;
		else cout << min(a[1],a[2]);
	}else{
		ll sum = 0;
		for(ll i = 1;i<=n/2;i++){
			if(c[i]!=c[n-i+1])sum++;
		}cout << sum;
	}
    return 0;
}
