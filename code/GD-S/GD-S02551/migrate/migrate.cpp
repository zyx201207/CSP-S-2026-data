#include<iostream>
#define N 2000005
using namespace std;
int c,t,n;
long long d,a[N],g[N];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long cnt=0,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=2;i<=n-1;i++)
		if(a[i+1]-a[i-1]<=d&&(a[i+2]-a[i-1]>d||i==n-1))
		g[++cnt]=i;
		if(cnt<2) cout<<0<<'\n';
		else{
			long long i=1,j;
			while(i<cnt){
				long long x=1,b=1,c=1;
				j=-2;
				while(a[g[i]+j]-a[g[i]+j-1]<=d&&a[g[i]+j+1]-a[g[i]+j-1]>d&&g[i]+j>1) j--,x++;
				for(j=1;a[g[i]]+j<a[g[i+1]];j++)
				if(a[g[i]+j]-a[g[i]+j-1]<=d&&a[g[i]+j+1]-a[g[i]+j-1]>d) b++;
				j=2;
				while(a[g[i+1]+j]-a[g[i+1]+j-1]<=d&&a[g[i+1]+j+1]-a[g[i+1]+j-1]>d&&g[i+1]+j<n) j++,c++;
				ans=ans+x*b*c;
				i++;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
