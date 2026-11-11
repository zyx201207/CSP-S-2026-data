#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,x[2000001],s,k,minn;
void dfs(int w,int ex,int t,int ans)
{
	if(w>ex)
	{
		return ;
	}
	if(w==ex)
	{
		if(minn>ans)
		{
			minn=ans;
			s=1;
		}
		else if(minn==ans)
		{
			s++;
		}
		else if(minn=-1)
		{
			minn=ans;
			s++;
		}
		return ;
	}
	for(int i=1;i<=d;i++)
	{
		bool sw=false;
		int j;
		for(j=t+1;j<=n;j++)
		{
			if(x[j]==w+i)
			{
				sw=true;
				break;
			}
		}
		if(sw)
		{
			dfs(w+i,ex,j,ans+1);
		}
	}
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=3;i<=n;i++)
		{
			for(int j=1;j<i,i-j>=3;j++)
			{
				s=0;
				minn=-1;
				dfs(x[j],x[i],j,0);
				if(s==2)
				{
					k++;
				}
			}
		}
		cout<<k<<endl;
		k=0;
		t--;
	}
	return 0;
}
