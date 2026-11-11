#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,a[2000005],n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int cnt=0,ans=0,sum=0x3f3f3f3f;
		for(int l=1;l<=n;l++){
			for(int r=l+3;r<=n;r++){
				sum=0x3f3f3f3f,cnt=0;
				for(int k=l+1;k<r;k++){
					if(a[k]-a[l]+a[r]-a[k]==sum&&a[k]-a[l]<=d&&a[r]-a[k]<=d)cnt++;
					else if(a[k]-a[l]+a[r]-a[k]<sum){
						cnt=1;
						sum=a[k]-a[l]+a[r]-a[k];
					}
					//cout<<l<<' '<<r<<' '<<k<<' '<<sum<<' '<<cnt<<'\n';
				}
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
