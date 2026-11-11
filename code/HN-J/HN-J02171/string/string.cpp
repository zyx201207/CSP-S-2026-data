#include <bits/stdc++.h>
using namespace std;

long long n,l=1,r,ans,nn1=1,nn2=1;

struct node
{
	long long x;
	char c;
}a[100010];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].c;
	}
	r=n;
	while(r>=l)
	{
		if(a[l].c==a[r].c)
		{
			int ll=nn1;
			nn1+=min(a[l].x+1-nn1,a[r].x+1-nn2);
			
			nn2+=min(a[l].x+1-ll,a[r].x+1-nn2);
		}
		else
		{
			int ll=nn1;
			ans+=min(a[l].x+1-nn1,a[r].x+1-nn2);
			
			nn1+=min(a[l].x+1-nn1,a[r].x+1-nn2);
			
			nn2+=min(a[l].x+1-ll,a[r].x+1-nn2);
		}
		if(nn1>a[l].x)
		{
			l++;
			nn1=1;
		}
		if(nn2>a[r].x)
		{
			r--;
			nn2=1;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


