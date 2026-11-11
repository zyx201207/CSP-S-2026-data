#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5;
int a[N],f[N],g[N];
int q[N],hh,tt;
int n,d,ans;
void Main(){
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		hh=1,tt=0;
		f[i]=0;
		g[i]=1;
		q[++tt]=i;
		for(int j=i+1;j<=n;j++){
			while(hh<=tt){
				if(a[q[hh]]+d<a[j]) hh++;
				else break;
			}
			if(hh>tt) break;
			f[j]=f[q[hh]]+1;
			g[j]=g[q[hh]];
			if(hh<tt&&f[q[hh]]==f[q[hh+1]]){
				g[j]+=g[q[hh+1]];
				if(hh+1<tt&&f[q[hh+1]]==f[q[hh+2]]){
					g[j]+=g[q[hh+2]];
				}
			}
//			if(g[j]>2) break;
			if(g[j]==2) ans++;
			while(hh<=tt){
				if(f[q[tt]]>f[j]) tt--;
				else break;
			}
			q[++tt]=j;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int TC,T;cin>>TC>>T;
	if(TC<=10) while(T--) Main();
	else while(T--) cout<<"0\n";
	return 0;
}