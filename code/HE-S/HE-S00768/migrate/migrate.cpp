#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,a[2000006];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c==11||c==12){
			int cnt=d/(a[2]-a[1]);
			int s=n-(cnt*2-1),m=n-(cnt+1);
			int f=(cnt*2-1)-(cnt+1)+1;
			int res=max(0,(s+m)*f/2);
			if(cnt&1)res>>=1;
			if(d>=a[n]-a[1])res=0;
			cout<<res<<'\n';
		}
		else cout<<"0\n";
	}
	return 0;
}
