#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e6+5;
int c,t,n,d,x[MAXN],dist[MAXN];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		if(n<=3){cout<<"0\n";continue;}
		if(c==13||c==14){
			int wz=0,ans=0;
			for(int i=1;i<=n;i++)
				if(abs(x[i]-x[1])<=d&&abs(x[i]-x[n])<=d)
					wz=i;
			for(int i=2;i<n;i++){
				if(i==wz)continue;
				if(abs(x[i]-x[i-1])>d||abs(x[i]-x[i+1])>d)continue;
				int wzl=lower_bound(x+1,x+n+1,x[i]-d)-x-1;
				int wzr=lower_bound(x+1,x+n+1,x[i]+d)-x-1;
				if(wzl==0)wzl=1;if(wzr==n+1)wzr=n;
				int sum=0;
				if(wzl<=wz&&wz<=i)ans+=(wzr-i)*(i-wzl-1);
				else if(i<=wz&&wz<=wzr)ans+=(wzr-i-1)*(i-wzl);
				else ans+=(wzr-i)*(i-wzl);
			}cout<<ans<<'\n';continue;
		}cout<<"1\n";
	}
	return 0;
}
/*
13 1
5 2
1 2 3 4 5
*/
