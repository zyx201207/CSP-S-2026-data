#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,top;
int f[5005][5005],w[5005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=m;i++)
	 for(int j=1;j<=m;j++)
	  if(i==j)f[i][j]=0;
	  else f[i][j]=1e9;
	for(int i=1;i<=n;i++){
		int len;cin>>len;
		vector<int> v1,v2;
		for(int j=1,x,y;j<=len;j++){
			cin>>x>>y;
			v1.push_back(x);
			v2.push_back(y);
		}
		for(int i=0;i<v1.size();i++)
		 for(int j=i+1;j<v1.size();j++)
		 	f[v1[i]][v1[j]]=f[v1[j]][v1[i]]=v2[i]+v2[j];
	}
	for(int k=1;k<=m;k++)
	 for(int i=1;i<=m;i++)
	   for(int j=1;j<=m;j++)
	       f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x,y;cin>>x>>y;
		cout<<f[x][y]+w[x]+w[y]<<"\n";
	}
}


