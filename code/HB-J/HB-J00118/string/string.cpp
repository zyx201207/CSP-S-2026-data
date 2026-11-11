#include <iostream>//AC!
using namespace std;
long long n,cnt=0,ans=0;
long long l,r;
struct node{
	long long a;
	char c;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	a[0]={0,'0'};
	for(int i=1;i<=n;i++)
	{
		long long aa;
		char c;
		cin>>aa;
		cin>>c;
		if(c==a[cnt].c) a[cnt].a=a[cnt].a+aa;
		else
		{
			cnt++;
			a[cnt]={aa,c};
		}
	}
	l=1;
	r=cnt;
	while(l<r&&l<=cnt&&r>=1)
	{
		if(a[l].c==a[r].c)
		{
			if(a[l].a==a[r].a)
			{
				l++;
				r--;		
			}
			else if(a[l].a<a[r].a)
			{
				a[r].a-=a[l].a;
				l++;
			}
			else
			{
				a[l].a-=a[r].a;
				r--;
			}
		}
		else
		{
			if(a[l].a==a[r].a)
			{
				ans+=a[l].a;
				l++;
				r--;
			}
			else if(a[l].a<a[r].a)
			{
				ans+=a[l].a;
				a[r].a-=a[l].a;
				l++;
			}
			else
			{
				ans+=a[r].a;
				a[l].a-=a[r].a;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
