#include<bits/stdc++.h>
using namespace std;
int c,t,n;
typedef long long ll;
const int N=2e6;
ll d,x[N],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;++i){
			cin>>x[i];
			if(x[i]-x[i-2]<=d&&x[i]-x[i-3]>d&&i-3>0)ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

