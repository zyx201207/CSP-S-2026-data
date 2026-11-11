#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long end;
	long long start;
	long long num;
	char c;
}a[200005];
long long n,x,num=0,ans=0,lo=0;
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++,num++)
	{
		bool b=0;
		cin>>x;
		a[num].num=x;
		cin>>a[num].c;
		if(a[num].c==c&&i!=0)
		{
			a[--num].num+=x;
			b=1;
		}
		else
		{
			c=a[num].c;
		}
		if(!b)
		{
			a[num].start=lo;
		}
		lo+=x;
		a[num].end=lo-1;
//		cout<<a[num].start<<' '<<a[num].end<<endl;
	}
//	cout<<lo<<' '<<num<<endl;
	for(long long l=0,r=num-1;l<r;)
	{
		long long e1=a[l].end,s2=lo-a[r].end-1,s1=a[l].start,e2=lo-a[r].start-1;
		if(a[l].c!=a[r].c)
		{
			ans+=min(e1,e2)-max(s1,s2)+1;
//			cout<<s1<<' '<<s2<<' '<<e1<<' '<<e2<<endl;
//			cout<<a[l].end<<' '<<a[r].end<<' '<<a[l].start<<' '<<a[r].start<<endl;
		}
		if(e1>e2)
		{
			r--;
		}
		else if(e2>e1)
		{
			l++;
		}
		else
		{
			r--;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
