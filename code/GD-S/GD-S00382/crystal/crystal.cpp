#include<bits/stdc++.h>
using namespace std;
const long long MAXX=1e18+2;
long long n,m,a[500010],ans,f[500010],cd[500010];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++){
		long long u=f[i-1]+(a[i]-a[i-1])*cd[i-1];
		if(u<=m){
			f[i]=u;
			cd[i]=cd[i-1]+1;
			ans=max(ans,cd[i]);
		}else{
			f[i]=0;
			cd[i]=1;
		}
	}
	cout<<ans;
	return 0;
}
