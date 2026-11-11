//GZ-S00388 六盘水市第二十四中学 姜知昊
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll sum;
ll maxn;
ll cnt=1;
ll r=1;
ll a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    	
    	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
while(r<=n){
	for(ll i=1;i<=r;i++){
		
			
			sum+=a[r]-a[i];
			
			if(sum>m){
			for(ll j=1;j<=n;j++){
			if(a[j]==a[j-1]){
				cnt++;
			}
			
			}
			maxn=max(maxn,cnt);
			r++;
			break;
		}
		a[i]=a[r];
		}
		r++;
	
	
}
		cout<<maxn;
	
	return 0;
} 
