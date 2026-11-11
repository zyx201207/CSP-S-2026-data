//GZ-S00134,刘雨航,北京师范大学贵阳附属中学 
#include<bits/stdc++.h>
using namespace std;
const int CRY=500005;
long long n,m,a[CRY],ans=0,sum,mb,i,j,t;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(i=n;i>=1;i--)
	{
		mb=m;
		sum=1;
		for(j=i-1;j>=1;j--)
		{
			t=a[i]-a[j];
			if(mb>=t)
			{
				mb-=t;
				sum++;
			}else
			{
				break;
			}
		}
		if(sum>=ans)ans=sum;
	}
	cout<<ans;
	return 0;
}
