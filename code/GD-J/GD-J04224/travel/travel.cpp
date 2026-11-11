#include<bits/stdc++.h>
using namespace std;
struct seat{
	int num;
	string le;
}a[2];
bool ans[3];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a[0].num>>a[0].le>>a[1].num>>a[1].le;
	if(a[0].num==a[1].num)
	{
		ans[0]=1;	
		if(a[0].le[0]==a[1].le[0]&&a[0].le[1]==a[1].le[1])
		{
			ans[1]=1; 
			if(a[0].le[2]<='C'&&a[0].le[2]>='A'&&a[1].le[2]<='C'&&a[1].le[2]>='A')
			{
				ans[2]=1;
			}
			else if(a[0].le[2]<='F'&&a[0].le[2]>='D'&&a[1].le[2]<='F'&&a[1].le[2]>='D')
			{
				ans[2]=1;
			}
			else
			{
				ans[2]=0;
			}
			if(a[0].le[2]+1==a[1].le[2]||a[0].le[2]-1==a[1].le[2])
			{
				ans[3]=1;
			}
			else
			{
				ans[3]=0;
			} 
		}
		else
		{
			ans[1]=0;
			ans[2]=0;
			ans[3]=0;
		}
	}
	else
	{
		ans[0]=0;
		ans[1]=0;
		ans[2]=0;
		ans[3]=0;
	}
	cout<<ans[0]<<ans[1]<<ans[2]<<ans[3];
	return 0;
} 
