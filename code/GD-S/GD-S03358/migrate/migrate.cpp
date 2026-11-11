#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2000010,inf=1e9;
int ID;
int n;
ll d,a[N];
int f[N],g[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(ID==11||ID==12){
		ll k=d/(a[2]-a[1]);
		if(k<=1)cout<<"0\n";
		else cout<<max(0ll,n-2*k+1)<<'\n';
		return;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)f[j]=inf,g[j]=0;
		f[i]=0,g[i]=1;
		for(int j=i+1;j<=n;j++)for(int k=i;k<j;k++)if(a[j]-a[k]<=d){
			if(f[k]+1<f[j])f[j]=f[k]+1,g[j]=g[k];
			else if(f[k]+1==f[j])g[j]+=g[k];
		}
		for(int j=i+1;j<=n;j++)if(g[j]==2)ans++;
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int _;
	cin>>ID>>_;
	while(_--)solve();
    return 0;
}
