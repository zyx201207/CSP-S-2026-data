#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	cin>>s;
	int cnt;
	for(int i=s.size();i>=1;i--)
	{
		cnt++;
	}
	cout<<cnt;
		
	return 0;
}
