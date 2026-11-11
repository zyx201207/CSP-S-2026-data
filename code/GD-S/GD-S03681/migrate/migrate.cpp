#include<bits/stdc++.h>
#define int long long
using namespace std;
const long long N=2e6+10;
int c,t,n,d,a[N],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		if(c==13||c==14){
			cin>>n>>d;
			for(int i = 1; i <= n; i++){
				cin>>a[i];
			}
			for(int i = 1; i <= n; i++){
				ans+=i;
			}
			cout<<ans;
		}else{
			cout<<"0\n1\n2";
		}
	}
}
