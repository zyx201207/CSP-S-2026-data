#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,a[200005],ans;
bool is(int x,int y)
{
	for(int i=x+1;i<=y;i++) 
	{
		if(a[i]-a[x]<=d)
		continue;
		else
		{
			i--;
			if(a[y]-a[i]<=d&&a[y]-a[i-1]<=d)
			return 1;
			else
			return 0;
		}
	}
	return 0;
}
int main(){
	freopen("migreate.in","r",stdin);
	freopen("migreate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i+1]-a[i]<=d)
			for(int j=i+3;j<=n;j++)
			{
				if(a[j]-a[i]>d)
				{
					if(is(i,j))
					{
						ans+=(n-j);
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
