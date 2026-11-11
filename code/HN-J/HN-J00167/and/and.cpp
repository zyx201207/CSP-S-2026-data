#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=2e5+5;
int a[N];
int n,m;
int maxn=-1e9;
int maxn2=-1e9;
void dfs(int id,int sum,int cnt)
{
	if(cnt>m)
	{
		return ;
	}
	if(cnt==m)
	{
		maxn=max(maxn,sum);
		return ;
	}
	if(id>n)
	{
		return ;
	}
	dfs(id+1,sum&a[id],cnt+1);
	dfs(id+1,sum,cnt);
}
bool is_2dcm(int x)
{
	x++;
	while(x!=1)
	{
		if(x%2!=0)
		{
			return false;
		}
		x/=2;
	}
	return true;
}
bool is_2dcm2(int x)
{
	while(x!=1)
	{
		if(x%2!=0)
		{
			return false;
		}
		x/=2;
	}
	return true;
}
bool cmp(int x,int y)
{
	return x>y;
}
int lg[N];
int cnt0,cnt1,cnt2,cnt3;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int temp=pow(2,31);
	int ans=temp-1;
	bool flag=false;// 特殊性质A 
	bool flag2=false;// 特殊性质B 
	bool flag3=false;// 测试点16、17 
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(!is_2dcm(a[i]))//是否是2的次幂-1 
		{
			flag=true;
		}
		if(a[i]!=i-1) 
		{
			flag2=true;
		}
		if(a[i]>=4)
		{
			flag3=true;
		}
		if(a[i]==0)
		{
			cnt0++;
		}
		if(a[i]==1)
		{
			cnt1++;
		}
		if(a[i]==2)
		{
			cnt2++;
		}
		if(a[i]==3)
		{
			cnt3++;
		}
		ans&=a[i];
		maxn2=max(maxn2,a[i]);
	}
	if(m==1)//5分 
	{
		cout << maxn2;
		return 0;
	}
	if(m==n)//5分 
	{
		cout << ans;
		return 0;
	}
	if(m==2)//15分 +测试完毕 
	{
		int sum=-1e9;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				sum=max(sum,a[i]&a[j]);
			}
		}
		cout << sum;
		return 0;
	}
	if(!flag)//5分 &特殊性质A 
	{
		sort(a+1,a+n+1);
		int ans=temp-1;
		int cnt=0;
		for(int i=n;i>=1;i--)
		{
			if(cnt==m)
			{
				break;
			}
			ans&=a[i];
			cnt++;
		}
		cout << ans;
		return 0;
	}
	if(m==n-1)//10分&不确定 
	{
		sort(a+1,a+n+1);
		int ans=temp-1;
		int cnt=0;
		for(int i=n;i>=1;i--)
		{
			if(cnt==m)
			{
				break;
			}
			ans&=a[i];
			cnt++;
		}
		cout << ans;
		return 0;
	 } 
	if(is_2dcm2(n)&&!flag2) //10分&特殊性质B +测试完毕 
	{
		int ans=temp-1;
		int cnt=0;
		for(int i=n;i>=1;i--)
		{
			if(cnt==m)
			{
				break;
			}
			ans&=a[i];
			cnt++;
		}
		cout << ans;
		return 0;
	}
	if(!flag3)//10分 &不确定 
	{
		m-=(cnt1+cnt3);
		if(m<=0)
		{
			if(cnt3!=0)
			{
				cout << 3;
			}
			else
			{
				cout << 1;
			}
			return 0;
		}
		else
		{
			m-=cnt2;
			if(m<=0)
			{
				if(cnt3!=0)
				{
					cout << 2;
				}
				else
				{
					cout << 0;
				}
				return 0;
			}
			else
			{
				cout << 0;
			}
		}
	}
	if(n<=20)//25分 
	{
		dfs(1,temp-1,0);
		cout << maxn;
		return 0;
	}
	return 0;
}
/*
保底部分分65分 
*/
