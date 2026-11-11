#include <bits/stdc++.h>
using namespace std;
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int main()
{
	int l;
	cin >> l;
	long long s[1000];
	char c;
	string b;
	int cnt = 0,ans=0; 
	for (int i = 1;i <= l;i++)
	{
		cin >> s[i] >> c;
		for(int j = 1;j <= s[i];j++)
		{
			cnt++;
			b[cnt] = c;	
		}		
	}
	if (l == 1)
	{
		cout << 0;
	}
for (int i = 1;i<=cnt;i++)
    {
    	if(b[i] != b[cnt + 1 - i])
    	    {
    	        ans++;	
			}
	}
	cout << ans/2;
	
	return 0;
}
	
