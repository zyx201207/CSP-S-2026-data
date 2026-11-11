#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000001];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n-3;i++)
		{
			int j=i+3;//端点 
			//cout<<i<<" "<<j<<endl;
			if(a[j]-a[i]>d&&a[i+1]-a[i]<=d&&a[i+2]-a[i+1]<=d&&a[i+3]-a[i+2]<=d)
			{
				//cout<<i<<" "<<j<<endl;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
左边i，右边j ，中间两个是m,n 
啊！只有在中间有两个岛、i-j>d、 n-i<=d 啊不对 
应该是 两个点之间，先套一个4格合法外面再来一个只能单向

太好了我不会来看下一题 
abcd
a   b     c   d   e 
*/
