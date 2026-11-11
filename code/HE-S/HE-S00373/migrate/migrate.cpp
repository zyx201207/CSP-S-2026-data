#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll t,c,n,m,a[N],ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]+m+1==a[i+m+1]){
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
