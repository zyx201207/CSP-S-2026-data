#include<bits/stdc++.h>
using namespace std;
unsigned long long sum;
char cc[2000100];
struct Node 
{
	unsigned long long s;
	char c;
	unsigned long long fw;
}a[2000010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	unsigned long long ss=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s;
		cin>>a[i].c;
		sum+=a[i].s;
		a[i].fw=sum;
		if(sum<2000100)
		{
			int sss=0;
			int t=sum;
			for(int j=ss+1;j<=t;j++)
			{
				sss++;
				cc[j]=a[i].c;
			}
			ss+=sss;
		}
	}
	cout<<sum<<endl;
	char ch=a[1].c;
	bool ch1=true;
	for(int i=2;i<=n;i++)
	{
		if(a[i].c!=ch)ch1=false;
	}
	if(ch1)
	{
		cout<<0;
		return 0;
	}
	
	unsigned long long ll=a[1].s;
	bool ll1=true;
	for(int i=2;i<=n;i++)
	{
		if(a[i].s!=ll)ll1=false;
	}
	if(ll1)
	{
		unsigned long long sum1=0;
		for(int i=1;i<=n/2;i++)
		{
			if(a[i].c!=a[n+1-i].c)sum1+=a[i].s;
		}
		cout<<sum1;
		return 0;
	}
	if(sum<2000100)
	{
		int t=sum;
		int sumsum=0;
		for(int i=1;i<=t/2;i++)
		{
			if(cc[i]!=cc[t+1-i])sumsum++;
		}
		cout<<sumsum;
		return 0;
	}
	return 0;
}
