#include <bits/stdc++.h>
using namespace std;
int cnt=0;
int g[500100];
int b[500010];
int ans[500010];
int n,m;
int a[500010];
void cz(int i){
	if(b[a[i]]==0){
		g[++cnt]=a[i];
		b[a[i]]++;
	}
	else{
		int z=0;
		for(int x=1;x<=cnt;x++){
			if(g[x]==a[i]){
				z=x;
			}
		}
		int zz=0;
		for(int i=z;i<=cnt;i++){
			ans[g[i]]++;
			g[i]=0;
			zz++;
		}
		cnt-=zz;
		g[++cnt]=a[i];
	}
}
signed main(){
	ios::sync_with_stdio();
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		g[++cnt]=a[i];
		b[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		cz(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
