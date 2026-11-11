#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e6+101;
LL c,t,n,d;
LL zb[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(LL i=1;i<=n;i++)cin>>zb[i];
		if(c==11||c==12){
			LL cha=zb[2]-zb[1];
			d=labs(d/cha);
			LL t=d*2-1;
			if(d<=1||t>n){
				//cout<<d<<' '<<zb[2]-zb[1]<<' ';
				cout<<0<<'\n';
				continue;
			}
			else {
				//cout<<d<<' '<<zb[2]-zb[1]<<' ';
				cout<<(n-t)<<'\n';
			}
			continue;
		}
		LL t1=zb[N]-d,t2=zb[1]+d;
		LL gs=0;
		for(int i=1;i<=n;i++){
			if(zb[i]>=t1&&zb[i]<=t2)gs++;
		}
	}
	return 0;
} 
