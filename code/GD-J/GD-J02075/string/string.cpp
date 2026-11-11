#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,t=0,m=0,lm=-2,x;
	long long tong[1000] = {},tong2[1000];
	memset(tong,0,sizeof(tong));
	memset(tong2,0,sizeof(tong2));
	string a[2][3],h="00";
	string z[27] = {"0","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[1][1]>>a[1][2];
		for(int j = 1;j <= 26;j++)
		{
			if(z[j] == a[1][2])
			{
				x = j;
				break;
			}
		}
		long long l=0;
		for(int j = 0;j <= a[1][1].size()-1;j++)
		{
			l = l*10+a[1][1][j]-'0';
		}
		tong[x] += l;
		h = a[1][2];
	}
	for(int i = 1;i <= 26;i++)
	{
		if(tong[i] >= m)
		{
			lm = m;
			m = tong[i];
		}
		else if(tong[i] >= lm)
		{
			lm = tong[i];
		}
	}
	cout<<lm;
	return 0;
} 
