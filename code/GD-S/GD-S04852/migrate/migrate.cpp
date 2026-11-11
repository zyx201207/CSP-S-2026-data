#include<bits/stdc++.h>
#define int long long
using namespace std;
int id,t,n,d,a[2000005],s[2000005],f[305][2],ans;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	cin>>id>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>1) s[i]=s[i-1]+a[i]-a[i-1];
		}
		ans=0;
		for(int i=1;i<=n;i++){
			memset(f,0,sizeof(f));
			f[i][0]=1,f[i][1]=0;
			for(int j=i+1;j<=n;j++) f[j][0]=0,f[j][1]=1e9;
//			cout<<i<<" :  ";
			for(int j=i+1;j<=n;j++){
				int sum=0,pl=j-1;
				while(pl>=i&&s[j]-s[pl]<=d)
				{
					if(f[j][1]>f[pl][1]+1) f[j][1]=f[pl][1]+1,f[j][0]=f[pl][0];
					else if(f[j][1]==f[pl][1]+1&&f[j][0]<=100) f[j][0]+=f[pl][0];
					pl--;
				}
				if(f[j][0]==2) ans++;
//				cout<<f[j][0]<<" "<<f[j][1]<<endl;
			}
//			cout<<endl;
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++) s[i]=0;
	}
	return 0;
}
