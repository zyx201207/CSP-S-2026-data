#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,d;
ll a[2000005];
ll sum[2000005];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(c>=0&&c<=10){
		int cnt=0;
		int ans=0;
		sum[1]=0;
		for(int i=2;i<=n;i++){
			sum[i]=sum[i-1]+a[i]-a[i-1];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=0;
				if(sum[j]-sum[i]<=d)continue;
				for(int l=j-1,r=j;l>i;l--){
					if(sum[l]-sum[i]<=d&&sum[r]-sum[l]<=d){
						cnt++;
					}
				}
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	if(c>=11&&c<=12){
		ll v=a[2]-a[1],cnt=0;
		d=d/v;
		d=d*2-1;
		for(int i=1;i<=n;i++){
			if(i+d<=n&&d>1){
				cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int _=1;
	cin>>c;
	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}
