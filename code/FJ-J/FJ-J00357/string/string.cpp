#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int jg;
struct node
{
	int s,le;
}a[999999];
int idx=0;
int p,ans,i;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)   //ÕûºÏ 
	{
		int hsj;
		char leo;
		cin>>hsj>>leo;
		if(idx==0||a[idx].le!=leo)
		{
			idx++;
			a[idx].s=hsj;
			a[idx].le=leo;
		}
		else
		{
			a[idx].s+=hsj;
		}	
	}
//	for(int i=1;i<=idx;i++)
//	{
//		cout<<a[i].s<<' '<<(char)a[i].le<<endl;
//	}
	p=idx;
	i=1;
	while(i<p)
	{
		while(a[i].s>=a[p].s)
		{
			
			if(a[i].le!=a[p].le)
			{
				ans+=a[p].s;
			}	
			a[i].s-=a[p].s;
			p--;
		}
		if(a[i].le!=a[p].le)
		{
			ans+=a[i].s;
		}
		a[p].s-=a[i].s;
		i++;
	}
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
//CSP RP++ 

