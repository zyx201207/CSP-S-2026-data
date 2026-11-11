#include <bits/stdc++.h>
using namespace std;

const int N=500005;
int n,m,a[N],ans[N],last[N];
bool used[N];

void fast()
{
	ios::sync_with_stdio(false);
	  cin.tie(0);
	  cout.tie(0);
}

int main() 
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	fast();
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(!used[a[j]])
			{
				used[a[j]]=true;
				last[a[j]]=j;
			}
			else
			{
				for(int q=last[a[j]];q<j;q++)
				{
					used[q]=false;
				}
				used[a[j]]=true;
			}
		}
		for(int j=1;j<=m;j++)
		{
			ans[j]+=used[j];
			used[j]=false;
		}
		
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	
	
	
	return 0;
}
