#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e6+10;

int C,T,ans;
int n,d,x[N];
int dis[N],pos[N],f[N][2];

void solve(){
	ans=0;
	for(int i=1;i<=n;i++){
		int k=i;
		dis[i]=0;
		f[i][0]=f[i][1]=0;
		for(int j=i+1;j<=n;j++){
			while(x[j]-x[k]>d&&k<j) k++;
			if(k==j) break;
			dis[j]=dis[k]+1;
			if(k!=j-1&&dis[k]==dis[k+1]&&(k==j-2||dis[k+1]!=dis[k+2])) f[j][1]=f[k][0];
			else if(dis[k]!=dis[k+1]) f[j][0]=f[k][0]+1,f[j][1]=f[k][1];
			ans+=f[j][1];
		}
	}
}

signed main(){
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		solve();
		cout<<ans<<'\n';
	}
	
	return 0;
}
