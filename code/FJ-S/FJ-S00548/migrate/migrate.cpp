#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int x[100200];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=n+1;i<n+20;i++){
			x[i]=0x7f7f7f7f7f7f7f7f;
		}
		int ans=0,l=1,r=1,t1=1;
		for(l=1;l<=n&&r<=n;l++){
			while(x[r]-x[l]<=d&&r<=n)r++;
			if(x[r]-x[l]<=d)break;
			if(r>n)break;
			for(int j=r;x[j]-x[l]<2*d&&j<=n;j++){
				int t1=upper_bound(x+1,x+1+n,x[l]+d)-x-1;
				int t2=lower_bound(x+1,x+1+n,x[r]-d)-x;
				cout<<t1<<"  "<<t2<<endl;
				cout<<l<<" "<<j<<endl;
				if(t2-t1==-1)ans++;
			}
		}
		cout<<ans<<endl;
	}
}
// afo
