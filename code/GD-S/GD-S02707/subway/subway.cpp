#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10; 
int c,n,m,d,q;
long long ans[N][N],w[N],a[N],t[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(ans,0x3f,sizeof(ans));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j];cin>>t[i][a[j]];
			for(int l=1;l<j;l++)ans[a[l]][a[j]]=ans[a[j]][a[l]]=t[i][a[l]]+t[i][a[j]];
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			if(i==k)continue; 
			for(int j=1;j<=m;j++){
				if(i==j||k==j)continue;
				ans[i][j]=min(ans[i][j],ans[i][k]+ans[k][j]);
			}
		}
	}
	//for(int i=1;i<=m;i++){for(int j=i+1;j<=m;j++)cout<<i<<' '<<j<<' '<<ans[i][j]<<'\n';}
	//return 0;
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+ans[x][y]+w[y]<<'\n';
	}
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3 
1 2
*/
