#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
int main()
{
	freopen("strint.in","r",stdin);
	freopen("string.out","w",stdout);
	string S;
	long long n;
	int o = 1;
	cin >> n;	
	if(n = 1)
	{
		cout << "0";
		break;
	}
	bool j;
    long long sum = 0,sum2 = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> b[i];
		sum += a[i];
		if(b[i] != b[i-1])
		{
			j = false;
		}
	}
	if(j == true)
	{
		cout << 0;
	}
	for(int j = 1;j <= n;j++)
	{
	    
	     while(a[j] != 0)
	     {
	     	S[o] = b[j];
	     	a[j]--;
	     	o++;
		 }
	    
    }
	for(int i = 1;i <= n;i++)
	{
		for(int j = n;j >= 0;j--)
		{
			if(S[i] != S[j]&&S[i+a[i]] != s[j-a[n]])
			{
				sum2++;
			}
		}
	}
	cout << sum2;
	return 0;
 } 
