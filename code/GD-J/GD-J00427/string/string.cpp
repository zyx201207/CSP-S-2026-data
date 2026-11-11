#include<bits/stdc++.h>
using namespace std;
string s[300001];
long long a[300001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0,sum1=0,cn=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		sum+=a[i];
	}
	if(sum%2==1)
	{
		long long cnt=0;
		for(int i=1;i<=n;i++)
		{
			cnt+=a[i];
			if(cnt*2>sum)
			{
				a[i]--;
				break;
			}
		}
		sum--;
	}
	for(int i=1;i<=n;i++)
	{
		if(sum1*2<sum)
		{
			sum1+=a[i];
			if(sum1*2>=sum)
			{
				cn=i;
			}
		}
	}
	long long x=0,y=a[cn+1],xx=cn,yy=cn+1,ans=0,cnnt=0;
	x=abs((sum1-sum/2)-(a[cn]-(sum1-sum/2)));
	if(x==0)
	{
		xx--;
		x=a[xx];
	}
	//cout<<sum/2<<" "<<sum1<<" "<<b[cn-1]<<" "<<x<<" "<<y<<" "<<xx<<" "<<yy<<endl;
	while(x!=0 && yy!=n+1)
	{
		if(s[xx]!=s[yy])
		{
			ans+=min(y,x);
			//cout<<ans<<endl;
		}
		cnnt+=x;
		if(x<y)
		{
			y-=x;
			xx--;
			x=a[xx];
		}
		else if(y<x)
		{
			x-=y;
			yy++;
			y=a[yy];
		}
		else
		{
			xx--;
			x=a[xx];
			yy++;
			y=a[yy];
		}
	//	cout<<xx<<" "<<yy<<" "<<x<<" "<<y<<endl;
	}
	//cout<<x<<" "<<y<<" "<<cnnt<<" "<<sum<<endl;
	printf("%lld",ans);
	return 0;
}
