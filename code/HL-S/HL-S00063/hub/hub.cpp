#include<bits/stdc++.h>
using namespace std;
int m[4010][4010],n,k,dp[4001][4001];
int main(){
	int c,t,u,v;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(m,0x2f,sizeof(m));
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			cin>>u>>v;
			m[u][v]=m[v][u]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int p=1;p<=n;p++){
					if(m[i][p]+m[p][j]<m[i][j]){
						m[j][i]=m[i][j]=m[i][p]+m[p][j];
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			m[i][i]=1e9;
		}
		int maxn=-1,kc=0;
		for(int i=1;i<=n;i++){
			int minn=1e9;
			for(int j=1;j<=n;j++){
				if(m[i][j]<minn){
					minn=m[i][j];
					kc++;
				}
			}
			if(kc+1<k){
				minn++;
			}
			maxn=max(maxn,minn);
			kc=0;
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<m[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		cout<<maxn<<endl;
	}
	return 0;
}
