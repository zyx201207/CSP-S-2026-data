#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
		for(ll i=2;i<=n;i++){
			if(a[i]-a[i-1]>d){
				n=i-1;
				break;
			}
		}
		cout<<max(int(n-d-d+1),int(0))<<endl;
	}
	return 0;
}
