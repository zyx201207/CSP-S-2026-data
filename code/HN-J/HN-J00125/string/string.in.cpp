#include<bits/stdc++.h> 
using namespace std;
string s[2010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,n,cnt = 0;
	for(int i = 1; i <= n;i++)
	{
	cin >> n;
    	if(s[i+1]!= s[i])	
    	{
		cnt++;
    	}
	}
	cout << cnt;
	return 0;
}
