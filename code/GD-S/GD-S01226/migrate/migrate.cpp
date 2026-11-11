#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--){
		ll n,d;
		cin>>n>>d;
		vector<ll> arr(n+1);
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		ll ans=0;
		for(int i=1;i<n-1;i++){
			for(int j=i+2;j<=n;j++){
				if(abs(abs(arr[j])-abs(arr[j-1]))>d){
					break;
				}
				if(abs(abs(arr[j])-abs(arr[i]))+abs(abs(arr[i+1])-abs(arr[i]))==d*2){
					ans++;
					cout<<arr[j]<<" "<<arr[i]<<endl;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
