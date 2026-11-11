#include<bits/stdc++.h>
using namespace std;
int ce,n,m,w[5000010],d,q,a,b,k[501],ans;
struct node{
	int xb,p;
}lian[501][20001];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>ce;
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>lian[i][j].xb>>lian[i][j].p;
		}
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		cin>>a>>b;
		for(int j=1;j<=k[i];j++)
		{
			if(lian[i][j].xb==a||lian[i][j].xb==b){
				ans+=lian[i][j].p;
			}
		}
		ans=ans+w[a]+w[b];
		cout<<ans<<endl;
	}
	return 0;
 } 
