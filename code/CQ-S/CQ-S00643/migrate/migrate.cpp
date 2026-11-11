#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int T,n,op,x,f[N];
long long m,ans,a[N],s[N];
void solve(){
	ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(n==1){
		cout<<0<<'\n';
		return;
	}
	x=m/(a[2]-a[1]);
	if(op==11||op==12){
		if(x<2||1ll*n-x-x+1<0) cout<<0<<'\n';
		else cout<<1ll*n-x-x+1<<'\n';
		return;
	}
	for(int i=1;i<=n;++i){
		f[i]=0,s[i]=1;
		for(int j=i+1;j<=n;++j){
			f[j]=2e9,s[j]=0;
			for(int k=j-1;k>=i&&a[j]-a[k]<=m;--k){
				f[j]=min(f[j],f[k]+1);
			}
			if(f[j]==2e9) continue;
			for(int k=j-1;k>=i&&a[j]-a[k]<=m;--k){
				if(f[k]+1==f[j]) s[j]+=s[k];
			}
			if(s[j]==2) ++ans;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>op>>T;
	while(T--) solve();
	return 0;
}
