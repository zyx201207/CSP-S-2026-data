#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int weighs[500005],t[21][500005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>weighs[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int s;
			cin>>s;
			cin>>t[i][s];
		}
	}
	
	for(int i=0;i<q;i++)
	{
		int u,v;
		cin>>u>>v;
		int ans=weighs[u]+weighs[v];
		int r=rand()+rand()+rand();
		cout<<ans+r<<endl;
		}	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
