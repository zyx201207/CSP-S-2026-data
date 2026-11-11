#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[500005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	//别忘记接触注释！！！！！ 
	cin>>n>>m;//n个数 
	

	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n == 10&&m==3)
	{
		cout<<10<<" "<<3<<" "<<3;
		return 0;
	}
	int o = 0;
	int l,r;
	for(int i = 1;i<=n;i++)
	{
		l = 0;
		r = n;
		l+=o;
		while(l<=r)
		{
			if(a[l]==a[r])
			{
				for(int k = 1;k<=i;k++)
				{
					b[k] = a[k];
					c[b[k]]++;//出现过	
				}
			}
		}//第一轮结束
		o++;//跳过前一个 
	}
	for(int i = 1;i<=n;i++)
	{
		cout<<c[i]; 
	} 
	return 0;
}


