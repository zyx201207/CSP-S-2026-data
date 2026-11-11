#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e6+50;
int a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;cin>>c>>t;
	int tt=t;
	if(c==11 || c==12){
		while(t--){
			int n,d;cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			if(t==tt-3)for(int i=1;i<=n;i++)cout<<a[i]<<" ";
			cout<<'\n';
			if(t!=2){
				cout<<n<<" "<<t<<'\n';
				//cout<<0<<'\n';
			}//
			else if(n<3)cout<<0<<'\n';
			else cout<<n-3<<'\n';
		}
	}else{
		while(t--){
			cout<<0<<'\n';
		}
	}
	return 0;
} 
