#include<bits/stdc++.h>
using namespace std;
struct node
{
	char c;
	long long int num;
};
int n;
//3 2 a 2 b 1 c
node a[200010];
long long int cnt;
long long int ans;
int f;
int cmg(long long int l,long long int r)
{
	if(l>=r&&f==0)
	{
		
		f=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans+a[i].num;
			
		}
		if(l==r);
		{
			ans = ans-a[l].num;
		}
		cout<<ans;
		return 0;
	}
	else if(a[l].c==a[r].c)
	{
		int minn=min(a[l].num,a[r].num);	
		a[l].num=a[l].num-minn;
		a[r].num=a[r].num-minn;
		if(a[r].num==0)
		{
			r=r-1;
		}
		if(a[l].num==0)
		{
			l=l+1;
		}
		cmg(l,r);
	}
	else
	{
		if(a[l].num!=a[r].num&&a[l].num==min(a[l].num,a[r].num))
		{
		a[r].num=a[r].num-min(a[l].num,a[r].num);
		l=l+1;
	    }
		else
		{
		a[l].num=a[l].num-min(a[l].num,a[r].num);	
		r=r-1;	
		}
	}
	cmg(l,r);
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num;
		cin>>a[i].c;
		cnt+=a[i].num;
	}
	if(cnt%2==1)
	{
		int zs=0;
		for(int i=1;i<=n;i++)
		{
		   zs=zs+a[i].num;
			if(zs>=cnt/2+1)
			{
				a[i].num--;
				break;
			}
			
		}
	}
	cmg(1,n);
}
