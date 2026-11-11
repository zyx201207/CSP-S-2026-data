#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],l[N],r[N],pre[N],mp[N],f[N];
bool vis[N],vis2[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],r[a[i]]=i;
	for(int i=n;i>=1;i--)pre[mp[a[i]]]=i,mp[a[i]]=i;
	for(int i=1;i<=m;i++){
		int p=r[i],q=r[i],ans=0;
		for(int j=1;j<=n;j++)f[j]=0;
		for(int j=1;j<=m;j++)vis[j]=vis2[j]=0;
		bool fl=0;
		for(int j=q+1;j<=n;j++)vis[a[j]]=1;
		while(p){
			int ps=p;f[ps]=1;
			while(!vis[a[ps-1]]&&(!vis2[a[ps-1]]||!fl)&&ps>1)ps--,f[ps]=1;
			for(int j=pre[p]+1;j<p;j++){
				vis2[a[j]]=1;
				if(vis[a[j]])fl=1;
			}
			p=pre[p];
		}
		for(int i=1;i<=n;i++)ans+=f[i];
		cout<<ans<<' ';
	}
}
