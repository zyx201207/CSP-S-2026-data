#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long book[300005];
long long ans[300005];
queue<long long> card;
queue<long long> desk;
bool check(long long x)
{
	if(book[x]>=2) return 0;
	return 1;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","W",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long lun=1;lun<=n;lun++)
	{
		if(lun==1)
		{
			for(long long i=lun;i<=n;i++)
			{
				card.push(a[i]);
			}
			for(long long i=lun;i<=n;i++)
		    {
		    	book[a[i]]++;
		    }
		}
		for(long long i=lun;i<=n;i++)
		{
			if(check(card.front()))
			{
				desk.push(card.front());
				book[card.front()]--;
				card.pop();
			}
			else
			{
				for(long long i=1;i<=desk.size();i++)
				{
					card.push(desk.front());
					book[desk.front()]++;
					desk.pop();
				}
				desk.push(card.front());
				book[card.front()]--;
				card.pop();
			}
		}
		while(desk.empty())
		{
			card.push(desk.front());
			ans[desk.front()]++;
			book[desk.front()]++;
			desk.pop();
		}
	}
	for(long long i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	//041521a2509c10091407a260809c190821a030821a12091407b1205 ,06011407d19081521c2509d0215b0201!
	return 0;
}
