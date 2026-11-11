#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long n,m,sum;
long long er[31];
struct Node
{
	long long a;
	int w,zgw;
	bool b[31],flag;
}c[N];
void work(int x,int k)
{
	for(int i = 30;i >= 0;i--)
	{
		if(x >= er[i])
		{
			x -= er[i];
			c[k].b[i] = 1;
			c[k].w++;
			if(c[k].flag == 0)
			{
				c[k].flag = 1;
				c[k].zgw = i;
			}
		}
		else
		{
			c[k].b[i] = 0;
		}
	}
	return ;
}
bool cmp(Node x,Node y)
{
	/*if(x.zgw != y.zgw) return x.zgw > y.zgw;
	else
	{
		return x.w > y.w;
	}*/
	if(x.w != y.w) return x.w > y.w;
	else
	{
		return x.zgw > y.zgw;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	er[0] = 1;
	for(int i = 1;i <=30;i++)
	{
		er[i] = er[i - 1] * 2;
	}
	for(int i = 1;i <= n;i++)
	{
		cin>>c[i].a;
		work(c[i].a,i);
	}
	sort(c + 1,c + n + 1,cmp);
	sum = c[1].a;
	for(int i = 2;i <= m;i++)
	{
		
		sum = sum & c[i].a;
	}
	/*for(int i = 1;i <= n;i++)
	{
		for(int j = 0;j <= 30;j++) cout<<c[i].b[j]<<' ';
		cout<<endl;
	}*/
	cout<<sum;
	return 0;
}
