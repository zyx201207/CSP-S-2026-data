#include<bits/stdc++.h>
using namespace std;
void slove()
{
	int ans=0;
	int n,d;//岛屿数量，飞行距离 
	cin>>n>>d;
	vector<long long>x(n,0);//岛屿坐标
	vector<int>reach(n);//岛屿最远能达到的岛屿编号
	vector<vector<long long>>DP(n,vector<long long>(n,0));//最短走法数 
	for(int i=0;i<n;i++)
	cin>>x[i];
	int j=0;
	int delta=0;
 	for(int i=0;i<n;i++)
 	{
 		while(j<n-1&&delta+x[j+1]-x[j]<=d)
 		{
 			delta+=x[j+1]-x[j];
 			j++;
		}
		reach[i]=j;
		delta-=x[i+1]-x[i];
		for(int k=i+1;k<=j;k++)DP[i][k]=1;
    }
    
    cout<<ans<<endl;
    return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++)
	slove();
}
