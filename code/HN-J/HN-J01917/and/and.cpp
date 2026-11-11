#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
/*const int N=2e5+5;
int a[N];

//string s;
bool r[N];
int best=-1;
void dfs(int sum,int c)
{
	if(c==m)
	{
		if(sum>best) best=sum;
		
		for(int i=1;i<=n;i++)
		{
			r[i]=0;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(r[i]==0)
		{
		r[i]=1;
		dfs((r[i]|sum),c+1);
	    }
	}

}

int y(int j)
{
	int pp=0;
	while(j>0)
	{
		if((j^1)!=j)pp++;
		j=j>>1;
	}
	return pp; 
}*/
signed main()
{
	int f;
	int sum=0;
	//按位与  &  ^几次消几个1 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n==m)
	{
	for(int i=1;i<=n;i++)
	{
		cin>>f;
		if(i==1)
		{
			sum+=f;
		}
		else
		{
			sum=(sum&f);
		}
		cout<<sum;
		
	}
    }
	else
	{
	    for(int i=1;i<=n;i++)
	    {
		cin>>f;
		sum=max(f,sum);
        }
		cout<<sum;
	}
	return 0;
 } 
