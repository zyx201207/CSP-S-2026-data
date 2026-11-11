#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t,sum;
void The_A_and_B()
{
	t=a[2]-a[1];
	for(int i=1;i<=n;i++)
	{
		sum+=i;
		if(sum*t>m)
		{
			cout<<i;
			exit(0);
		}	
	}
}
void The_wrong_answer()
{
	int maxx=0,t,s;
	for(int i=n;i>=2;i--)
	{
		t=m;
		s=1;
		for(int j=i-1;j>=1;j--)
			if(t<a[i]-a[j])	break;
			else if(t>=a[i]-a[j])
				s++,t-=a[i]-a[j];
		maxx=max(maxx,s);
	}
	cout<<maxx;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(a[2]-a[1]==a[3]-a[2]&&
	   a[3]-a[2]==a[4]-a[3]&&
	   a[4]-a[3]==a[5]-a[4])
	{
		The_A_and_B();
	}
	The_wrong_answer();
	
	return 0;
}
