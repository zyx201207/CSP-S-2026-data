#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int mid;
	string a;
	int k;
	if(n%2==0)
	{
		mid=n/2;
		k=0;
	}
	else
	{
		mid=n/2;
		mid+=1;
		k=1;
	}
	int b[n+5];
	int h = mid-1;
		
	for(int i = 1; i <= mid; i++)
	{
		cin >> b[i];
		cin >> a[i];
	}
	int num=0;
	if(k==0)
	{ 
	
	for(int i = 1; i <= mid; i++)
	{
		for(int j = n; j > mid; j--)
		{
			if(a[i]==a[j])
			{
				num++;
			}
		}
	}
	if(num==mid)
	{
		cout << 0;
		return 0;
	}
    }
    else
    {
    
	for(int i = 1; i <= mid; i++)
	{
		for(int j = n; j > mid; i++)
		{
			if(a[i]==a[j])
			{
				num++;
			}
		}
	}
	if(num==h)
	{
		cout << 0;
		return 0;
	}
	}
	cout << 1;
	
	return 0;
}
