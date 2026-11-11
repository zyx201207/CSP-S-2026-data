#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s, s1;
	int x;
	long long sum=0;
	int f = 1;
	for(int i=1;i<=n;i++)
	{
		int l;
		char c;
		cin >> l >> c;
		sum += l;
		if(i==1) x=l;
		else{
			if(x!=l) f = 0;
		}
		s1 += c;
		for(int j=1;j<=l;j++) s += c;
	}
	if(f==1){
		int ans = 0;
		for(int i=0;i<n/2;i++)
		{
			if(s1[i] != s1[n-1-i]) ans++;
		}
		cout << ans*x;
	}
	else
	{
		int ans = 0;
		for(int i=0;i<sum/2;i++)
		{
			if(s[i] != s[sum-1-i]) ans++;
		}
		cout << ans;	
	} 
	return 0;
 } 
