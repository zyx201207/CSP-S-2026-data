#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=2e6+5;
const ll INF=0x3f3f3f3f3f3f3f3f;
int c,tim,n;
ll d,dis[N][2],a[N],ans;
void Sub1 () {
	ans=0;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			dis[j][0]=INF;
			dis[j][1]=0;
		}
		dis[i][0]=0;
		dis[i][1]=1;
		for(int j=i+1,k=i;j<=n;j++) {
			while(k<=j&&a[j]-a[k]>d) {
				k++;
			}
			if(j==k) {
				break;
			}
			dis[j][0]=dis[k][0]+1;
			dis[j][1]=dis[k][1];
			for(int p=k+1;p<=min(k+2,j-1);p++) {
				if(dis[p][0]+1==dis[j][0]) {
					dis[j][1]+=dis[p][1];
				}
			}
			if(dis[j][1]==2) {
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
}
void Sub2 () {
	ll cnt=d/(a[2]-a[1]);
	ans=0;
	for(int i=1;i<=n;i++) {
		if(cnt>1&&i+cnt+cnt-1<=n) {
			ans++;
		}
	}
	cout<<ans<<"\n";
}
int main () {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>tim;
	while(tim--) {
		cin>>n>>d;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
		if(n==1) {
			cout<<"0\n";
			continue;
		}
		if(c==11||c==12) {
			Sub2();
		}else {
			Sub1();
		}
		
	}
	return 0;
}
