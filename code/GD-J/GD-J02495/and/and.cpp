#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[200005];
int maxn = -1e9;
int maan = 1;

int er(int n)
{
	if(n == 1) return 10000;
	if(n == 2) return 01000;
	if(n == 3) return 11000;
	if(n == 4) return 00100;
	if(n == 5) return 10100;
	if(n == 6) return 01100;
	if(n == 7) return 11100;
	if(n == 8) return 00010;
	if(n == 9) return 10010;
	if(n == 10) return 01010;
	if(n == 11) return 11010;
	if(n == 12) return 00110;
	if(n == 13) return 10110;
	if(n == 14) return 01110;
	if(n == 15) return 11110;
	if(n == 16) return 00001;
	if(n == 17) return 10001;
	if(n == 18) return 01001;
	if(n == 19) return 11001;
	if(n == 20) return 00101;
}
int shi(int n)
{
	if(n == 1) return 1;
	if(n == 10) return 2;
	if(n == 11) return 3;
	if(n == 100) return 4;
	if(n == 101) return 5;
	if(n == 110) return 6;
	if(n == 111) return 7;
	if(n == 1000) return 8;
	if(n == 1001) return 9;
	if(n == 1010) return 10;
	if(n == 1011) return 11;
	if(n == 1100) return 12;
	if(n == 1101) return 13;
	if(n == 1110) return 14;
	if(n == 1111) return 15;
	if(n == 10000) return 16;
	if(n == 10001) return 17;
	if(n == 10010) return 18;
	if(n == 10011) return 19;
	if(n == 10100) return 20;
}
int yu(int a,int b)
{
	int ans = 0;
	while(a != 0 && b != 0)
	{
		if(a%10==1 && b%10==1)
		{
			ans = ans * 10 + 1;
		}
		a /= 10;
		b /= 10;
	}
	return ans;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
		if(a[i] > maxn) maxn = a[i];
	}
	if(m == 1) cout << maxn;
	else if(m == 2){
		for(int i = 0;i < n;i++)
		{
			for(int j = i+1;j < n;j++)
			{
				//if(i&j > maan) maan = i&j;
				int x = er(i);
				int y = er(j);
				if(shi(yu(x,y)) > maan) maan = shi(yu(x,y));
			}
		}
		cout << maan;
	}
	else
	{
		cout << a[3];
	}
	return 0;
}
