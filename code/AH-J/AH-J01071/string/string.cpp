#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,sum=0,l=0,r,ma=0;
	cin>>n;
	if(n==1)
	{
		cout<<0;
		return 0;
	} 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	r=sum;
	long long li=1,ri=n,ss1=0,ss2=0;
	while(l<r&&l<=sum/2&&r>=sum/2)
	{
		if(ss1==0) 
		{
			l+=a[li];ss1=a[li];
		}
		if(ss2==0) 
		{
			r-=a[ri];ss2=a[ri];
		}
		if(l>sum/2) ss1=sum/2-l+ss1;
		if(r<sum/2+1) ss2=r+ss2-sum/2;
		if(ss1>ss2)
		{
			if(b[li]!=b[ri]) 
			{
				ma+=ss2;
				ss1-=ss2;
				ss2=0;
				
			}else
			{
				ss1-=ss2;
				ss2=0;
			}
			ri--;
		}else
		{
			if(b[li]!=b[ri]) 
			{
				ma+=ss1;
				ss2-=ss1;
				ss1=0;
				
			}else
			{
				ss2-=ss1;
				ss1=0;
			}
			li++;
			if(ss1==ss2) ri--;
		}
	}
	cout<<ma;
	return 0;
}
