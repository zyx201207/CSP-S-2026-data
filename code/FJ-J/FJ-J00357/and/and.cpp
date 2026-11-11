#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
//int a[999999];
int num;
map<int,int>mp;
struct node
{
	int b,c;                  //b用来排序，c是原来的数 
}a[999999];
bool cmp(node hsj,node leo)
{
	return hsj.b>leo.b;
}
int akaitoude(int x)
{
	for(int i=0;i<=30;i++)
		if(pow(2,i)>x)
			return pow(2,i-1);
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i].b;
		a[i].c=a[i].b;
	}
	num=n;
	while(num>m)
	{
		sort(a+1,a+num+1,cmp);
		int h=akaitoude(a[m].b);
		//cout<<h<<endl;
		if(h==0)
			break;
		for(int i=1;i<=num;i++)
		{
			if(a[i].b<h)
			{
				num=i-1;
				break;
			}
			a[i].b%=h;
		}
	}
	int ans=a[1].c;	
	for(int i=2;i<=m;i++)
	{
		ans&=a[i].c;
		//cout<<a[i].c<<' ';
	}
//	for(int i=1;i<=n;i++)
//		cout<<a[i];
	cout<<ans;
	return 0;
}
/*
4 2
19 12 12 3
*/
