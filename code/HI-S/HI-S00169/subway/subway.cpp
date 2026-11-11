#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int time_n[n+1];
	for(int i=1;i<=n;i++)
		cin>>time_n[i];
	int time_m[n+1][d+1];
	int num_m[n+1][m+1];
	int num_n[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>num_n[i];
		for(int j=1;j<=num_n[i]*2;j++)
			cin>>num_m[i][j]>>time_m[i][j];
 	}
    while(q--)
	{
     	int x;cin>>x;
    	int y;cin>>y;
    	int ans=0;
     	ans+=time_n[x]+time_m[x][1];
    	
    }
	fclose(stdin);fclose(stdout);
	return 0;
}
