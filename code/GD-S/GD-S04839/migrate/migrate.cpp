#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t;
int n,d,a[N],nxt[N],g[N][2];
bool vis[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while (t--){
		cin>>n>>d;
		for (int i=1;i<=n;i++)cin>>a[i];
		int j=1;
		for (int i=1;i<=n;i++){
			while (j<n&&a[j+1]-a[i]<=d)j++;
			nxt[i]=j;
		}
//		for (int i=1;i<=n;i++)cout<<nxt[i]<<' ';
//		cout<<'\n';
		int ans=0;
		for (int j=n;j>=1;j--){
			g[j][0]=1;
			for (int i=1;i<=n;i++)nxt[i]=min(nxt[i],j);
			for (int i=j-1;i>=1;i--){
				if (nxt[i]==i)break;
				ans+=g[nxt[i]][1];
				g[i][0]=g[nxt[i]][0];
				g[i][1]=g[nxt[i]][1]; 
				if (nxt[i]==nxt[i+1]&&i+1<j){
					g[i+1][1]=g[i+1][0];
					g[i+1][0]=0;
				}
				if (nxt[i]==nxt[i+2]&&i+2<j){
					g[i+2][1]=g[i+2][0];
					g[i+2][0]=0;
				}
			}
//			cout<<j<<' '<<ans<<'\n';
			for (int i=1;i<=n;i++)g[i][0]=g[i][1]=0;
		}
		cout<<ans<<'\n';
//		for (int i=1;i<=n;i++){
//			for(int j=i+3;j<=n;j++){
//				int k=i,op=0;
//				while (op<2){
//					if (nxt[k]==k)break;
//					int tar=nxt[k];
//					if (tar>=j){
//						tar=j;
//						for (int l=k-1;l>=max(i,k-3);l--)
//							if (nxt[l]>=tar)op++;
//						break;
//					}
//					else 
//						for (int l=k-1;l>=max(i,k-3);l--)
//							if (nxt[l]>=tar)op++;
//					k=nxt[k];
//				}
//				if (op==1&&nxt[k]>=j){ans++;}
//			}
//		}
//		for (int i=1;i<=n;i++)nxt[i]=0;
//		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 1
6 4
-3 0 1 2 3 4

*/
