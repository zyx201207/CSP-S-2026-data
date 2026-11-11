#include <bits/stdc++.h>
using namespace std;
long long n,k;
const int MAXN=2e5+10;
struct node{
	long long x;
	char s;
}a[MAXN],p[MAXN];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].x >> a[i].s;
	}
	for(int i=1;i<=n;i++)
	{
		node ans={a[i].x,a[i].s};
		while(a[i].s==a[i+1].s)
		{
			ans.x+=a[i+1].x;
			i++;
		}
		p[k++]=ans;
	}
	long long sum=0,i=0,j=k-1;
	while(i<=j)
	{
		node e=p[i],f=p[j];
		if(e.s==f.s)
		{
			node v={0,e.s};
			if(e.x==f.x)
			{
				i++;
				j--;
			}
			else if(e.x>f.x)
			{
				v.x=e.x-f.x;
				j--;
				p[i]=v;
			}
			else
			{
				v.x=f.x-e.x;
				i++;
				p[j]=v;
			}
		}
		else
		{
			sum+=min(e.x,f.x);
			if(e.x>f.x)
			{
				p[i].x-=f.x;
				j--;
			}
			else if(e.x<f.x)
			{
				p[j].x-=e.x;
				i++;
			}
			else
			{
				i++,j--;
			} 
		}
	}
	cout << sum;
	/*for(int i=0;i<k;i++)
	{
		cout << p[i].x << " " << p[i].s << "\n";
	}*/
}
