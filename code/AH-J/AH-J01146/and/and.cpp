#include<bits/stdc++.h>
using namespace std;
long long a[100010];
long long ans=0;
long long n,m;

int main()
{	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	

	cin>>n>>m;
//	cout<<n<<"!!!!!!!!!!!!!!!!!!"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	//	cout<<"Ok"<<i<<' '<<a[i]<<"  ";
	}
	if(n<=20)//debug
	{
		//int as=0;
		for(int i=0;i<1048576;i++)
		{
			int s=0;
			int t=i;
			int tm=i;
			while(t)
			{
				int w=t%2;
				s=s+w;
				t=t/2;
			}
			
			if(s==m)
			{
				long long int y=(1<<20)-1;
				int now=0;
				while(tm)
				{
					int is;
					is=tm%2;
					if(is)
					{
						y=y&a[now];
					}
					now++;
					tm=tm/2;
				}
				ans=max(y,ans);
			}
		}
		cout<<ans;
		return 0;
	}
	else
	{
		if(m==1)
		{
			for(int i=0;i<n;i++)
			{
				ans=max(a[i],ans);
			}
			cout<<ans;
			return 0;
		}
		else if(m==n)
		{
			ans=a[0];
			for(int i=1;i<n;i++)
			{
				ans=ans&a[i];
			}
			cout<<ans;
		}
		else if(m==2)
		{
			//cout<<n<<m;
			int ti=0,tj=0;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(i!=j)
					{
						int k=a[i]&a[j];
						if(k>ans)
						{
							ans=k;
							ti=i;
							tj=j;
						}
					}
				}
			}
			cout<<ans;
		}
		else if(m==n-1)
		{
			for(int i=0;i<n;i++)
			{
				long long t=a[0];
				for(int j=0;j<n;j++)
				{
					if(i!=j)
					t=t&a[j];
				}
				ans=max(t,ans);
			}
			cout<<ans;
		}
		else
		{
			sort(a,a+n,greater<int>());
			ans=a[0];
			for(int i=0;i<m;i++)
			{
				ans=ans&a[i];
			}
			cout<<ans;
		}
	}
	return 0;
}
//Technoblade never died!!!

