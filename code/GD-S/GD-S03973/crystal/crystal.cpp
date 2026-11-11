#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],ans,L=1,n,m,sum;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	sort(a+1,a+1+n);
	for(int R=1;R<=n;R++)
	{
		sum+=(R-L)*(a[R]-a[R-1]);
		//cout<<a[R]<<" "<<sum<<endl;
		while(L<=R)
		{
			if(sum>m)
			{
				sum-=(a[R]-a[L]);
				L++;
			}
			else break;
		}
		ans=max(ans,R-L+1);
	}
	cout<<ans;
	return 0;
} 
