#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ki;
int w[500005];
int a[505][50005];
int x[100005],y[100005];
int ans;
int t[505][50005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	cin>>ki;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=ki;j++)cin>>a[i][j]>>t[i][j];
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		ans+=w[x[i]]+w[y[i]];
		int ii=0,ok=1;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				for(int l=k;l<=n;l++){
					if(a[j][k]==a[j][l]&&ok==1){
						ii=j;
						ok=0;
					}
				}
			}
		}
		if(d<=2)cout<<ans+t[ii][1]+t[ii][2]<<'\n';
		else cout<<ans+t[1][x[i]]+t[1][y[i]]<<'\n';
	}
	return 0;
} 
