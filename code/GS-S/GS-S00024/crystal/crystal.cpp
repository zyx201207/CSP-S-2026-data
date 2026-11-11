#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 50010;
int a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	long long m;
	cin >> n >> m;
	long long ans = 0;
	for(long long i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
    long long t = 0;
	if(n / 2 == 0)
	{
		t += n / 2;
	}else if(n / 2 != 0)
	{
		t += n / 2 + 1;
	}
	for(long long i = 1;i <= t;i++)
	{
		for(long long j = 1;j <= n;j++)
	   	{
	   		if(a[i] != a[t])
	   	{
	   		a[i]++;
	    }
	   	else{
	   		break;
	   	}
		}
	}
	for(long long i = 1;i <= n;i++)
	{
		if(a[i] == a[t])
		{
			ans++;
		}
		else
		{
			break;
		}
	}
	//Tian Xin is nine one artict
	//RYA,SYW 
	cout << ans;
	return 0;
}
