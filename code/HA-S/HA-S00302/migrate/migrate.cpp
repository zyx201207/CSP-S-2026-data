#include<bits/stdc++.h>
#define int long long
#define N 2000005
#define pii pair<int,int>
#define x first
#define y second
#define mod 998244853
using namespace std;
int C,Tc=1,n,d,ne[N],a[N],pre[N],f[305][305],g[305][305];
void solve(int cs){
	cin>>n>>d;
	if(C>=11&&C<=12){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1,j=1;i<=n;i++){
			while(j<n&&a[j+1]-a[i]<=d)j++;
			ne[i]=j;
		}
		for(int i=n,j=n;i;i--){
			while(j>1&&a[i]-a[j-1]<=d)j--;
			pre[i]=j;
		}
		int res=0;
		for(int i=1;i<=n;i++){
			int nee=ne[ne[i]];
			if(nee<=i+1||ne[i]<=i+1)continue;
			if(pre[nee]==ne[i]-1)res++;
			if(pre[nee-1]==ne[i]-1)res++;
		}
		cout<<res<<'\n';
		return;
	}
	if(C>=13&&C<=14){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int p=0;
		for(int i=1;i<=n;i++){
			if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
				p=i;
				break;
			}
		}
		int c0=0,c1=0;
		for(int i=1;i<p;i++){
			if(a[p+1]-a[i]<=d)c0++;
			else c1++;
		}
		int d0=0,d1=0;
		for(int i=p+1;i<=n;i++){
			if(a[i]-a[p-1]<=d)d0++;
			else d1++;
		}
		cout<<c0*d1+c1*d0<<'\n';
		return;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++){
			f[i][j]=2e18;
			g[i][j]=1;
		}
	}
	for(int i=1,j=1;i<=n;i++){
		while(j<n&&a[j+1]-a[i]<=d)j++;
		ne[i]=j;
		for(int k=i;k<=ne[i];k++){
			f[i][k]=f[k][i]=1;
		}
	}
	for(int i=n,j=n;i;i--){
		while(j>1&&a[i]-a[j-1]<=d)j--;
		pre[i]=j;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(f[i][k]+f[k][j]<f[i][j]){
					f[i][j]=f[i][k]+f[k][j];
					g[i][j]=g[i][k]*g[k][j]%mod;
				}
				else if(f[i][k]+f[k][j]==f[i][j]){
					(g[i][j]+=g[i][k]*g[k][j])%=mod;
				}
			}
		}
	}
	int res=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(g[i][j]==2){
				res++;
			}
		}
	}
	cout<<res<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C;
	cin>>Tc;
	for(int cs=1;cs<=Tc;cs++){
		solve(cs);
	}
	return 0;
}
