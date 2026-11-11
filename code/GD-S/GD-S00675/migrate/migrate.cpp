#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000007];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(n==1){
			cout<<"0\n";
			continue;
		}
		if(c==11||c==12){
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			int x=d/(a[n]-a[n-1]),ans=0;
			for(int i=1;i<=n;i++){
				if(n-i+1>=2*x-1) ans+=x-1;
				else if(n-i+1>x) ans+=n-i+1-x;
			}
			cout<<ans<<"\n";
			continue;
		}
			
		
	}
	return 0;
}

