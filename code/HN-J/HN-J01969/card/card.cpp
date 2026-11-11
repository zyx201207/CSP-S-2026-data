#include<bits/stdc++.h>
using namespace std;

#define mj long long

mj a[1000000] , n , m , b[1000000] , aa[10000000];

int main()
{
	
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	cin >> n >> m;
	for(mj i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[a[i]] = i;
	}
	mj i = n + 1;
	while(i--)
	{
		if(i < 1)break;
		mj ans1 = b[a[i]];
		aa[a[ans1]]++;
		while(ans1 != n)
		{
			if(ans1 < n)
			{
				ans1++;
			}else break;
			aa[a[ans1]]++;
			if(ans1 != b[a[ans1]])ans1 = b[a[ans1]];
		}
	} 
	for(int i = 1; i <= n; i++)if(aa[i] != 0)cout << aa[i] <<" ";
	
}
