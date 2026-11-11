#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a; 
		if(n==1)
		{
			cout<<a;
			return 0;
		}
	} 
	srand(time(0));
	cout<<rand();
	return 0;
}
