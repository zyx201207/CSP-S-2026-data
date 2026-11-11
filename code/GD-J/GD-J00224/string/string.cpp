#include<bits/stdc++.h>
using namespace std;
long long n,num,t,mid,ans;//t为前半段长度，mid为中间值 
string card,new1;//new1为前半段字符串； 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		long long a;
		string b;
		cin >> a >> b;
		for (int i = 1;i <= a;i++)
		{
			card += b;
		}
		num += a;
	}
	if(num%2 == 0)
	{
		t = num/2;
		mid = t;
	}
	else
	{
		t = (num-1)/2;
		mid = t+1;
	}
	long long q = t;
	for (int i = 1;i <= t;i++)
	{
		new1 += card[q-1];
		q--;
	}
	int e = 0;
	for (int i = mid;i < card.size();i++)
	{
		if(card[i] != new1[e])
		{
			ans++;
		}
		e++;
	}
	cout << ans;
	return 0;
 } 
