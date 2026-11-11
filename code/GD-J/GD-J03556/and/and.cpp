#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,sum=0;
void dfs(int num,int step,int sum)
{
	if(step>=m)
	{
		num++;
		step=1;
		return;
	}
	if(num==n)
	{
		cout << ans;
		exit(0);
	}
	//int a1=sum;
	for(int j=num+1; j<=n; j++)
	{
		//if(step==1) a1=a[num]&a[j];
		//else a1=a1&a[j];
		//ans=max(ans,a1);
		//a1=sum;
		sum=max(sum,a[num]&a[j]);
		
	}
	ans=max(ans,sum);
	//sum=ans;
	dfs(num,step+1,sum);
	return;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	ans=0;
	for(int i=1; i<n; i++)
	{
		for(int j=i+1; j<=n; j++)
		{
			sum=max(sum,a[i]&a[j]);
		}
		ans=max(ans,sum);
	}
	//dfs(1,1,1);
	cout << ans;
	return 0;
}


	
