#include<bits/stdc++.h> 
using namespace std;
string n[2010];
int main()
{
	freopen("and.in", "r",stdin);
	freopen("and.out","w",stdout) ;
	int a,m,maxn;
	cin >> m;
	for(int i = 1; i <= m; i++)
	{
		if(n[i] >= n[i+1])
		{
			maxn  += n[i];
		}
		else
		{
			  = n[i+1];
		}
		
	}
	cout << maxn;
	return 0;
}
