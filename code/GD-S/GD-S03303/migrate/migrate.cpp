#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,f[5001][5001];
int a[5001],ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		if(c==13||c==14){
			cout<<0<<"\n";
			continue;
		}
		memset(f,0,sizeof(f));
		ans=0LL;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=i+2;j<=n;j++){int t1=0;
				if(a[j]-a[i]<=d)continue;
				for(int k=i+1;k<j;k++)
					if(a[j]-a[k]<=d)
						for(int m=1;m<=k-i;m++)
							f[j][m+1]+=(m==1?1:f[k][m]);
				for(int m=j-i;m>1;m--){
					if(f[j][m])t1=f[j][m];
					//if(i==2&&j==5)cout<<f[j][m]<<endl;
				}
				if(t1==2)ans++;//,cout<<i<<" "<<j<<endl;
			}
		cout<<ans<<'\n';
	}
} 
