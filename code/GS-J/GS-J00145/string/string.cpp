#include<bits/stdc++.h>
using namespace std;

const int N = 100000;
char a[N];

int main()
{
	freopen("string.in","r",stdin);
	freoprn("string.out","w".stdout);
	
	int n;
	cin>>n;
	int r = 1;
	int w = n;
	int ans = 0;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
		if(r==w && r+i==w-i)
		{
			cout<<"0";
			break;
		}
		else
		{
			a[n+1-i] = a[i];
			ans++;	
		}
		cout<<ans;
			
	}
	return 0;
}
