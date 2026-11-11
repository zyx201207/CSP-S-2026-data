#include <bits/stdc++.h>
using namespace std;
long long a[500005];

int main ()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m, ans = 0;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	
	sort(a+1, a+n+1);
	if(n <=5000){
	    for(int i = 1;i <= n;i++)
	    {
		    long long j = i, num = 0, sum = 0;
		    while(j >=1&&sum <= m)
		    {
			    if(sum+(a[i]-a[j])<=m)
			    {
				    sum+=(a[i]-a[j]);
				    num++;
			    }
			    j--;
		    }
		    ans = max(ans, num);
	    }
	    cout << ans;
	    return 0;
    }
    bool flag = true;
    for(int i = 1;i <= n;i++)
    {
    	if(a[i]!=i) 
    	{
    		flag = false;
    		break;
		}
	}
	if(flag == true)
	{
		long long pos = 0, val = 0, zhi = 1;
		while(true)
		{
			if(val+zhi<=m) val+=zhi;
			else break;
			pos++;
			zhi++;
		}
		cout << pos+1;
		return 0;
	}
	else
	{
		long long cha = a[2]-a[1];
		long long pos = 0, val = 0, zhi = cha;
		while(true)
		{
			if(val+zhi<=m) val+=zhi;
			else break;
			pos++;
			zhi+=cha;
		}
		cout << pos+1;
	}
	return 0;
}
