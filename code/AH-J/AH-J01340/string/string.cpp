#include<bits/stdc++.h>
using namespace std;
const int M = 2e5 + 5;
struct node
{
	int num;
	char c;
}s[M];
node nowl , nowr;
int main()
{
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    	cin >> s[i].num >> s[i].c;
    nowl = s[1] , nowr = s[n];
    int l = 1 , r = n;
    long long ans = 0;
    while(l < r)
    {
    	if(nowl.num < nowr.num)
    	{
    		if(nowl.c == nowr.c)
    		{
    			l++;
    			nowr.num -= nowl.num;
    			nowl = s[l];
			}
			else
			{
				ans += nowl.num;
				l++;
				nowr.num -= nowl.num;
				nowl = s[l];
			}
		}
		else if(nowl.num == nowr.num)
		{
			if(nowl.c != nowr.c)
				ans += nowl.num;
			l++ , r--;
			nowl = s[l] , nowr = s[r]; 
		}
		else
		{
			if(nowl.c == nowr.c)
			{
				r--;
				nowl.num -= nowr.num;
				nowr = s[r];
			}
			else
			{
				ans += nowr.num;
				r--;
				nowl.num -= nowr.num;
				nowr = s[r];
			}
		} 
	}
	cout << ans;
	return 0;
}
