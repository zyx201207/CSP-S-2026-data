#include<bits/stdc++.h>
using namespace std;
int z,n,m,d,q,c[505][500005],cnt[505];
bool vis[505];
struct point{
	int w,a[505],b[505],cnt;
}a[280005];
int dfs(int i,int ans,int r){
	for(int j=0;j<a[r].cnt;j++) if(a[r].b[j]==i) return ans+a[r].a[i]+a[r].w;
	int he=10000000;
	for(int j=0;j<cnt[i];j++){
		point &u=a[c[i][j]];
		if(u.cnt>1){
			for(int k=0;k<u.cnt;k++){
				if(!vis[u.b[k]]){
					vis[u.b[k]]=1;
					he=min(he,dfs(u.b[k],ans+u.a[i]+u.a[u.b[k]],r));
					vis[u.b[k]]=0;
				}
			}
		}
	}
	return he;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>z>>n>>m>>d>>q;
	for(int i=0;i<m;i++) cin>>a[i].w;
	for(int i=0;i<n;i++){
		int p;
		cin>>p;
		for(int j=0;j<p;j++){
			int o;
			cin>>o;
			o--;
			cin>>a[o].a[i];
			a[o].b[a[o].cnt]=i;
			a[o].cnt++;
			c[i][j]=o;
			cnt[i]++;
		}
	}
	while(q--){
		int r,l;
		cin>>l>>r;
		l--;
		r--;
		memset(vis,0,sizeof(vis));
		int y=10000000;
		for(int i=0;i<a[l].cnt;i++){
			vis[a[l].b[i]]=1;
			y=min(y,dfs(a[l].b[i],a[l].w+a[l].a[a[l].b[i]],r));
			vis[a[l].b[i]]=0;
		}
		cout<<y<<endl;
	}
	return 0;
}
