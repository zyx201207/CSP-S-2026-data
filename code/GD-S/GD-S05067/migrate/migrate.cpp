#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e8+5;
ll c,t,n,d,ans=0;
ll x[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		
		cout<<ans<<'\n';
	}
	return 0;
} 
