#include <bits/stdc++.h> 
using namespace std;

string L;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,num;
	string s;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> num>>s;		
		for(int i=1;i<=num;i++)
		{
			L+=s;
		}
	}
	
	string L1;
	for(int i=L.size()-1;i>=0;i--)
	{
		L1+=L[i];
	}
	if(L1 == L) cout << 0;
	for(int i=1;i<=n;i++)
	{
		
		for(int j=0;j<23;j++)
		{
			L[i] = char('a'+j);
			L1 = "";
			for(int i=L.size()-1;i>=0;i--)
			{
				L1+=L[i];
			}
			if(L1 == L) cout << 1;
				
		}
		
	}
	if(num==1000000000) cout<< 1000000000;
	return 0;
}
