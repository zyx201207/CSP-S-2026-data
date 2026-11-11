#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x,y[2005],z[2005],dis[2005][2005],f[2005],l,r;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>f[i];
	for(int i=1;i<=n+m;i++) for(int j=1;j<=n+m;j++) dis[i][j]=114514191981023333;
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>y[j]>>z[j];
			dis[n+y[j]][i]=dis[i][n+y[j]]=z[j];
		}
	}
	for(int k=1;k<=n+m;k++) for(int i=1;i<=n+m;i++) for(int j=1;j<=n+m;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		cin>>l>>r;
		cout<<f[l]+f[r]+dis[n+l][n+r]<<endl;
	}
	return 0;
}
//I am qu,I can not solve that problem./bxbxbxbxbxbxbxbxbxbxbxbxbxbxbxbxbxbxbxbxbxbxbxbxbxbxbxbxbxbxbxbxbxbxbxbxbxbxbxbxbxbxbxbx
//I love yangyang and feixue.
//Give them really wars!
