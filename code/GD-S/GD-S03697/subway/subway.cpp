#include <bits/stdc++.h>
using namespace std;
long long w[21000],k[510];
int p[2100][2100]; 
int a[510][21000],t[510][21000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;int r=m;int l;
	for(int i=1;i<=m;i++) cin>>w[i];
	memset(p,0x3f,sizeof(p));
	for(int i=1;i<=n;i++){
		cin>>k[i];l=r+1;
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			p[a[i][j]][++r]=t[i][j];
			p[r][a[i][j]]=t[i][j];
		}
		for(int j=l+1;j<=r;j++){
			p[j][j-1]=p[j-1][j]=0;
		}
	}
	for(int k=1;k<=r;k++){
		for(int i=1;i<=r;i++){
			for(int j=1;j<=r;j++){
				p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
			}
		}
	}
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<p[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
