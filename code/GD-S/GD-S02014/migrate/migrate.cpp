#include<bits/stdc++.h>
#define int long long
using namespace std;
int q,t,n,k,a[2000005],c[2000005],f[200005][2],l,r,s;
void solve(){
	s=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(c,0,sizeof(c));
		memset(f,0,sizeof(f));
		l=i,f[i][0]=0,f[i][1]=1,c[1]=1;
		for(int j=i+1;j<=n;j++){
			while(a[j]-a[l]>k) c[f[l][0]+1]-=f[l][1],l++;
			f[j][0]=f[l][0]+1,f[j][1]=c[f[j][0]];
			c[f[j][0]+1]+=f[j][1];
			if(f[j][1]==0) break;
			if(f[j][1]==2) s++;
		}
	}
	cout<<s<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>q>>t;
	while(t--) solve();
	return 0;
}
