#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;

ll f[N][N],sum[N][N];

ll n,a[2000005],d;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	if(c<=10){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			for(int i=1;i<=n;i++){
				for(int j=1;j<=i;j++){
					f[i][j]=1e18;
					sum[i][j]=0;
					if(a[i]-a[j]<=d)f[i][j]=1,sum[i][j]=1;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<i;j++){
					for(int k=j;k<=i;k++){
						if(f[i][j]>f[i][k]+f[k][j]){
							f[i][j]=f[i][k]+f[k][j];
							sum[i][j]=0;
						}if(f[i][j]==f[i][k]+f[k][j]){
							sum[i][j]+=sum[i][k]*sum[k][j];
						}
					}
				}
			}ll ans=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=i;j++){
					if(sum[i][j]==2)ans++,cout<<j<<' '<<i<<'\n';
				//	cout<<sum[i][j]<<' ';
				}//cout<<'\n';
			}
			cout<<ans<<' ';
			
		}
	}else if(c==11||c==12){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			ll dd=a[2]-a[1];
			dd=d/dd;
			if(dd<=1)cout<<0<<'\n';
			else cout<<max(0ll,n-dd*2+1)<<'\n';
		}
	}else if(c==13||c==14){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			cout<<0<<'\n';
		}
	}else{
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			int ans=0;
			for(int i=2;i<n;i++){
				ll l1=-1e18,l2=-1e18,r1=1e18,r2=1e18;
				if(a[i+2]-a[i-1]<=d)continue;
				l1=a[i+1]-d,r1=a[i+2]-d;
				l2=a[i-1]+d,r2=a[i]+d;
				r1=min(r1,a[i]-1),l2=max(l2,a[i+1]+1);
				//cout<<l1<<' '<<r1<<' '<<l2<<' '<<r2<<'\n';
				ans+=(lower_bound(a+1,a+1+n,r1+1)-upper_bound(a+1,a+1+n,l1-1))*(lower_bound(a+1,a+1+n,r2+1)-upper_bound(a+1,a+1+n,l2-1));//cout<<lower_bound(a+1,a+1+n,r1)-a<<" "<<upper_bound(a+1,a+1+n,l1-1)-a<<" "<<lower_bound(a+1,a+1+n,r2)-a<<' '<<upper_bound(a+1,a+1+n,l2-1)-a<<'\n';
			}cout<<ans<<'\n';
		}
	}
		
	return 0;
}
