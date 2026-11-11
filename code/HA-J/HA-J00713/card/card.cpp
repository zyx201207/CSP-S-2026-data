#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,num,p; 
int a[1000005];
int f[1000005];
int b[1000005];
int ans[1000005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	if(m==2)
	{
		if(a[n]==1&&a[n-1]==1)
		{
			cout<<n<<" "<<0;
			return 0;
		}
		if(a[n]==1&&a[n-1]==2)
		{
			cout<<n<<" "<<n-1;
			return 0;
		}
		if(a[n]==2&&a[n-1]==2)
		{
			cout<<0<<" "<<n;
			return 0;
		}
		if(a[n]==2&&a[n-1]==1)
		{
			cout<<n-1<<" "<<n;
			return 0;
		}
	}
	if(m==1)
	{
		cout<<n;
		return 0;
	}
	int i=2;
	for(int o=1;o<=n;o++)
	{
		queue<int>q;
		num=0;
		memset(f,0,sizeof f);
		for(int j=i-1;j<=n;j++)
		{
			if(f[a[j]]==-1)
			{
				p=0;
				for(int k=b[a[j]];k<=num;k++)
				{
					p++;
					f[q.front()]=1;
					q.pop();
					//f[a[k]]=1;
					//num--;
				}
				q.push(a[j]);
				b[a[j]]=j;
				num++;
				num-=p;
				continue;
			}
			f[a[j]]=-1;
			b[a[j]]=j;
			q.push(a[j]);
			num++;
		//	cout<<a[j]<<" ";
		}
		//cout<<endl<<num<<endl;
		for(int j=1;j<=num;j++)
		{
			ans[q.front()]++;
		    q.pop();
		}
//		for(int j=1;j<=q.size();j++)
//		{
//			ans[q.front()]++;
//		    q.pop();
//		}
		i++;
	//	cout<<endl;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	
    
	return 0;
}
