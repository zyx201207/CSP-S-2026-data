#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,ans;
int a[2000005];
int f[305][305];
int sum[305][305];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n<=300){
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++) f[i][j]=1e18;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(abs(a[i]-a[j])<=d) f[i][j]=1,sum[i][j]=1;
			for(int k=1;k<=n;k++)
				for(int i=1;i<=n;i++)
					for(int j=1;j<=n;j++)
						if(f[i][j]>f[i][k]+f[k][j]){
							f[i][j]=f[i][k]+f[k][j];
							if(sum[i][k]*sum[k][j]>2) sum[i][j]=3;
							else if(sum[i][k]*sum[k][j]==2) sum[i][j]=2;
							else sum[i][j]=1;
						}
						else if(f[i][j]==f[i][k]+f[k][j]){
							if(sum[i][k]*sum[k][j]+sum[i][j]>2) sum[i][j]=3;
							else sum[i][j]=2;
						}
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++) if(sum[i][j]==2) ++ans;
			cout<<ans<<"\n";
		}
		else{
			int D=a[2]-a[1],k;
			d=d/D*D;
			k=(d-1)/D;
			for(int i=1;i<=n&&k;i++)
				if(a[i]+d+k*D<=a[n]) ans+=k;
				else{
					int l=0,r=k,num=-1;
					while(l<=r){
						int mid=(l+r)/2;
						if(a[i]+d+mid*D<=a[n]) l=mid+1,num=mid;
						else r=mid-1;
					}
					if(num==-1) break;
					else ans+=num,k=num;
				}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
