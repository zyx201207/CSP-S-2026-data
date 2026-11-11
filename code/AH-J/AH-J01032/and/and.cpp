#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int num[N],n,m,maxn=INT_MIN,alsum=INT_MAX,s1=0,s2=0,s3=0,minn=INT_MAX,anssss=INT_MIN;
bool iflog=true,is1=false,is2=false,is3=false,issmall4=true,used[N];
bool isint(double x)
{
	int it=x;
	double x2=it*1.00;
	if(x2==x)
	return 1;
	else return 0;
}
void dfs(int step,int sum)
{
	if(step==m)
	{
		anssss=max(anssss,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!used[i])
		{
			used[i]=1;
			dfs(step+1,sum&num[i]);
			used[i]=0;
		}
	}
	return;
}
//5 3 0 1 4 5 6
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in" ,"r",stdin );
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
		used[i]=0;
		maxn=max(maxn,num[i]);
		minn=min(minn,num[i]);
		alsum=alsum&num[i];
		if(!isint(log2(num[i]+1)*1.00)) iflog=false; 
		if(num[i]==1) is1=true,s1++;
		if(num[i]==2) is2=true,s2++;
		if(num[i]==3) is3=true,s3++;
		if(num[i]>=4) issmall4=false;
	}
	if(iflog)//样例13-A
	{
		sort(num+1,num+n+1);
		int ans=INT_MAX;
		for(int i=n;i>=n-m+1;i--)
		{
			ans=ans&num[i];
		}
		cout<<ans;
	}
	else
	{
		if(m==1)//样例6
		{
			cout<<maxn;
			return 0;
		}
		else if(m==2)//样例8-10
		{
			maxn=INT_MIN;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<i;j++)
				{
					maxn=max(maxn,num[i]&num[j]);
				}
			}
			cout<<maxn;
			return 0;
		}
		else if(m==n)//样例7
		{
			cout<<alsum;
			return 0;
		}	
		else if(m==n-1)//样例11-12
		{
			bool used=false;
			int ans=INT_MAX;
			for(int i=1;i<=n;i++)
			{
				if(num[i]!=minn||used) ans=ans&num[i]; 
				else used=true;
			}
			cout<<ans;
			return 0;
		}	
		else if(issmall4)//样例16-17
		{
			if(s3>=m) cout<<3;
			else 
			{
				if(s2>=m||s3+s2>=m) cout<<2;
				else if(s1>=m||s1+s3>=m) cout<<1;
				else cout<<0;
			}
			return 0;
		}
		else //样例1-5
		{
			dfs(0,INT_MAX);
			cout<<anssss;
			return 0;
		}
	}

}
