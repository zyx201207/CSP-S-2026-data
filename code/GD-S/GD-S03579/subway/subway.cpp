#include<bits/stdc++.h>

using namespace std;
const int N = 2e4+5;
const int maxn = 1e9;
typedef pair<int,int> pii;

struct node{
	int to,w,next;
}e[505<<2];

bool vis[505];
int c,n,m,T,d,cnt,s,ed,ans[505][N];
int a[505][N],t[505][N],k[N],w[N];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>T;
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=n;i++){
		cin>>k[i];
		for (int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j];
		
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			ans[i][j]=maxn;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (i==j) {ans[i][j]=w[i];continue;}
			for (int ii=1;ii<=k[i];ii++)
				for (int jj=1;jj<=k[j];jj++)
					if (a[i][ii]==a[j][jj])
						ans[i][j]=min(t[i][ii]+t[j][jj],ans[i][j]);
		}
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (maxn==ans[i][j])
					ans[i][j]=min(ans[i][k],ans[k][j]);
	
	while (T--)
	{
		cin>>s>>ed;
		cout<<ans[s][ed]<<endl;
	}
	
	return 0;
}
