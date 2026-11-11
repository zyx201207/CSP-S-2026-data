#include<bits/stdc++.h>
using namespace std;
long long n,s,sum1,sum2;
struct st
{
	int x;
	char y;
}a[1000005];
string x,y;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x;
		cin>>a[i].y;
		s+=a[i].x;
	} 
	long long f=0;
	if(s%2==1) f=1;
	s/=2;
	long long ss=0,sss=0;
	for(int i=1;i<=n;i++)
	{
		ss+=a[i].x;
		if(ss>s)
		{
			if(f==1) a[i].x--,ss--;
			a[i].x=ss-s;
			break;
		}
	}
	for(int i=1,j=n;i<j;)
	{
		if(a[i].y!=a[j].y)
		{
			sum1+=min(a[j].x,a[i].x); 
		}
		if(a[j].x>a[i].x)
		{		
			a[j].x-=a[i].x;
			a[i].x=0;
		}
		else
		{
			a[i].x-=a[j].x;
			a[j].x=0;
		}
		if(a[i].x<=0) i++;
		if(a[j].x<=0) j--;
	}
	cout<<sum1;
	return 0;
} 
