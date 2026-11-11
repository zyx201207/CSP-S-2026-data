#include<bits/stdc++.h>
using namespace std;
int x[600005];
int ans[600005];




 
int count(int j,int d) //从j出发，到达d时经过了几座岛 
 {
 	int s,i = 0;
 	int lc;//路程 
 	while(x[i] - x[j] <= d){
 		if(x[i] - x[j] <= d) s++;
 		i++;
 		
	}
	return s;
 }
 

int find(int j,int i,int d)//从第j个岛到达第i个岛的路径数
{
	int ans = 0;
	if(i == 1) return 1;
	if(x[i]-x[j] <= d)
	{
		for(int k = j;k < i;k++)
		{
			ans += find(j,i-k,d);
		}
	}else{
		for(int l = j;l <= count(x[j],d);l++)
		{
			for(int m = count(x[j],d);m < i-count(x[j],d);m++)
			{
				ans += find(j,i-m,d);
			}
		}
	}
	return ans;
 } 


int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","r",stdout);
	int c,t,temp,n,d;
	cin>>c>>t;
	for(int i = 0;i < t;i++)
	{
		cin>>n>>d;
		for(int kdsfd = 0;kdsfd < n;kdsfd++)
		{
			cin>>x[kdsfd];
		}
		
		for(int j = 0;j <= n;j++)//j为起始点，k为终点 
		{
			for(int k = j+1;k < n;k++)
			{
				if(find(x[j],x[k],d) == 2) ans[t]++;
			}
		}
	}
	for(int i = 0;i < t;i++) cout<<ans[t]<<" ";

	return 0;
	
	 
}
