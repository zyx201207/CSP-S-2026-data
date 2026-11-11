#include<bits/stdc++.h>
using namespace std;
int n;
long long l=0;
struct node{
	long long x=0,y=0;
	char ch;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char s;
		cin>>x>>s;
		a[i].x=l+1;
		a[i].y=l+x;
		a[i].ch=s;
		cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].ch<<endl;
		l=a[i].y;
	}
	long long sum=a[n].y/2;
	int j1=1,j2=n;
	char ch1=a[j1].ch,ch2=a[j2].ch;
	for(long long i1=1;i1<=a[n].y/2;i1++)
	{
		long long i2=a[n].y-i1+1;
		while(i1>a[j1].y)
		{
			j1++;
			if(i1<=a[j1].y)
			ch1=a[j1].ch;
		}
		while(i2<a[j2].x)
		{
			j2--;
			if(i2>=a[j2].x)
			ch2=a[j2].ch;
		}
		if(ch1==ch2)
		sum--;
	}
	cout<<sum;
	return 0;
}

