#include<bits/stdc++.h>
using namespace std;
int a[500005],n,m,f_i_n_d=0,k;
long long L[5005];
bool case_B=1,case_A=1; 
void function_1()//全部同时转正 
{
	for(int i=1;i<=n;i++)
	    a[i]*=-1; 
	sort(a+1,a+n+1);
}
void function_2()//同时加k 
{
	for(int i=1;i<=n;i++)
	    a[i]*=-a[1]; 
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	if(i==2)k=a[2]-a[1];
    	if(a[i]-a[i-1]!=k&&i>2)case_B=0;//找B 
    	if(a[i]!=i)case_A=0;//找A 
    	if(a[i]<0)f_i_n_d++;//找负数 
	}
	sort(a+1,a+n+1);
	if(case_A==1)//找情况A 
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			cnt=(1+i)*i/2;
			if(cnt==m)
			{
				cout<<i+1;
				return 0;
			}
			if(cnt>m)
			{
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	else if(case_B==1)//找情况B 
	{
		if(f_i_n_d==n)//全负数转正 
			function_1();
		else if(f_i_n_d!=0)//同时+最小 
			function_2();
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			cnt=(a[1]+a[i])*i/2;
			if(cnt==m)
			{
				cout<<i+1;
				return 0;
			}
			if(cnt>m)
			{
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	else if(n<5000)//找特解 
	{
		for(int i=n;i>=1;i--)//找最大,尝试找到特例： 
		{
			if(n==i)//类似前缀和 
			{
				for(int j=1;j<n;j++)
					L[i]+=a[i]-a[j];
			}
			else L[i]=L[i+1]-(a[i+1]-a[i])*i;
			if(L[i]==m)
			{
				cout<<i;
				return 0;
			}
		}
		//找大部分解 
		int max_res=0;//记录最大结果 
		for(int i=n;i>=1;i--)//分层_找最近（排序后越近需要越小）,i表示第i个宝石 
		{
		   long long sum=0;//需要的操作数 
		   for(int j=i-1;j>=1;j--) //算第i层与其前面的几个层数之差 
		   {
		   	    sum=sum+(a[i]-a[j]);//记录第i层与其最近层数的差 
				if(sum==m) //若最近几层需要的数刚好与提供需要的数一样 记录可填充层数 
		   	    {
					int res=i-j;
					max_res=max(max_res,res);
					break;
				} 
				if(sum>m)
				{
					int res=i-j+1;
					max_res=max(max_res,res);
					break;
				}
		   }
		}
		cout<<max_res;
	}
	else//最坏情况 
		cout<<0;
	return 0;
}
