#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		int x;
		char q;
		cin >> x >> q;
		for (int i=1;i<=x;i++)
		{
	        s+=q;
		}
	}
	long long len=0;
	long long cnt=0;
	for (int i=1;i<=s.size()/2;i++)
	{
		if (s[len]!=s[s.size()-1-len])
		{
			cnt++;
			len++;
		}
	}
	cout << cnt;
	return 0;
} 
