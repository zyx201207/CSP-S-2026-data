#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int vis[500100];
int dis[300100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int vtt=n;
		for(int j=i;j<=n;j++){
			int y=0;
			for(int ij=1;ij<=n;ij++){
				if(a[ij]==a[j]&&vis[ij]==0){
					vis[ij]=1;
					for(int op=ij+1;op<=vtt;op++){
						vis[op]=1;
					}
					vtt++;
					a[vtt]=a[j];
					y=1;
				}
			}
			if(y==0){
				vtt++;
				a[vtt]=a[j];
			}
		}
		for(int j=1;j<=vtt;j++){
			if(vis[j]==0){
				dis[a[j]]++;
			}
		}
		for(int j=1;j<=n;j++){
			vis[j]=0;
		}
		for(int j=n+1;j<=vtt;j++){
			a[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<dis[i]<<" ";
	}
	return 0;
}
