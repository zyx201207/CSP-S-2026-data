//GZ-S00142 ½¯•Fê» 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],ans,mb;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		//q.push(a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		mb=0;
		for(int j=i;j>=1;j--)
		{
			
			mb+=(a[i]-a[j]);
			long long o=i-j+1;
			if(mb>m)
			{
				break;
			}
			if(o>ans)
			{
				ans=o;
			}
		}
	}
	cout<<ans;
	return 0;
}//5 5 1 2 4 8 9
//5 8 -3 -1 2 2 7
//5 3 -3 -1 2 2 7
