#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],c[500010],vis[500010],mem[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int idx=0;
		memset(vis,0,sizeof(vis));
		memset(c,0,sizeof(c));
		memset(mem,0,sizeof(mem));
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				vis[a[j]]=1;
				mem[a[j]]=++idx;
				c[idx]=a[j];
			}
			else{
				int jian=0;
				for(int i=1;i<=m;i++){
					if(mem[i]>=mem[a[j]]&&i!=a[j]){
						mem[i]=0;
						vis[i]=0;
						jian++;
					}
				}
				idx-=jian;
			}
		}
		for(int j=1;j<=idx;j++){
			b[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
