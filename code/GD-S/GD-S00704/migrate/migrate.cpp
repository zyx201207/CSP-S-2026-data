#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
ll n,m,ans=0;
ll a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		ans=0;
		cin>>n>>m;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		if(n<4){
			cout<<"0";
			continue;
		}
		if(m<abs(a[1]-a[3])){
			cout<<"0";
			continue;
		}
		for(int i=1;i<=n;i++){
			if(i+3<=n){
				ans++;
			}
		}
		cout<<ans;
	}
}
