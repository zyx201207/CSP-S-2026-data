#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5*1e5+10;
ll c,t,n,d;
ll x[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<n;i++){
			int y;
			cin>>x[i]>>y;
		}
		cout<<max(x[1],x[n])<<'\n';
	}
	return 0;
}
