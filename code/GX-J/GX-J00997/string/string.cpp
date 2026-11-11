#include<iostream>
#include<string>
using namespace std;
struct cha
{
	int num;
	char c;
}a[200010];
int n,tot;
unsigned long long ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	a[0]=(cha){0,'1'};
	for(int i=1;i<=n;i++)
	{
		int x; char y;
		cin>>x; cin>>y;
		if(y==a[tot].c) {a[tot].num+=x; continue;}
		a[++tot].num=x; a[tot].c=y;
		//a[i]=(cha){x,y};
	}
	for(int i=1,j=tot;i<=tot && j>=1;)
	{
		if(i==j) break;
		if(a[i].c!=a[j].c)
		{
			if(a[i].num<=a[j].num)
			{
				ans+=a[i].num;
				a[j].num-=a[i].num;
				if(a[j].num==0) j--;
				i++;
			}
			else
			{
				ans+=a[j].num;
				a[j].num-=a[i].num;
				j--;
			}
		}
		else
			if(a[i].num<=a[j].num)
			{
				a[j].num-=a[i].num;
				if(a[j].num==0) j--;
				i++;
			}
			else
			{
				a[i].num-=a[j].num;
				j--;
			}
	}
	cout<<ans;
	return 0;
}
