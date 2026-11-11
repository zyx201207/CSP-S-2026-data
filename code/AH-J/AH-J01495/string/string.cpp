#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
char u;
struct GGB{
	long long shu;
	char ci;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>m>>u;
		a[i].ci=u;
		a[i].shu=m;
	}
	long long l=1,r=n,l1=0,r1=0;
	char s1=a[1].ci,s2=a[n].ci;
	while(l<r)
	{
		if(s1==s2)
		{
			if(a[l].shu-l1>a[r].shu-r1)
			{
				l1+=(a[r].shu-r1);
				r1=0;
				r--;
				s2=a[r].ci;
			}
			else if(a[l].shu-l1<a[r].shu-r1)
			{
				r1+=(a[l].shu-l1);
				l1=0;
				l++;
				s1=a[l].ci;
			}
			else
			{
				r1=l1=0;
				l++;
				r--;
				s1=a[l].ci;
				s2=a[r].ci;
			}
		}
		else
		{
			if(a[l].shu-l1>a[r].shu-r1)
			{
				l1+=(a[r].shu-r1);
				ans+=(a[r].shu-r1);
				r1=0;
				r--;
				s2=a[r].ci;
			}
			else if(a[l].shu-l1<a[r].shu-r1)
			{
				r1+=(a[l].shu-l1);
				ans+=(a[l].shu-l1);
				l1=0;
				l++;
				s1=a[l].ci;
			}
			else
			{
				ans+=(a[l].shu-l1);
				r1=l1=0;
				l++;
				r--;
				s1=a[l].ci;
				s2=a[r].ci;
			}
		}
		
	}
	cout<<ans;
	return 0;
}
