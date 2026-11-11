#include <bits/stdc++.h>
using namespace std;
string a[1000005];
char x;
bool flag = false;
int n,k,sum,num,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> k >> x;
		num += k;
		for(int j = 1;j <= k;j++)
		{
			sum++;
			a[sum] = x;
		}
	}
	for(int i = 1;i < num;i++)
	{
		if(a[i+1] != a[i]){
			flag = true;
			break;
		}
	}
	for(int i = 1;i <= num/2;i++)
	{
		if(num % 2 == 0)
		{
			if(a[i] != a[num/2+i]){
				ans += 1;
		    }
		}
		else
		{
			if(a[i] != a[num/2+i+1]){
				ans += 1;
		    }
		}
	}
	if(!flag)
		cout << "0";
	else
		cout << ans;
	return 0;
}
