//and
#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and,out","w",stdout);
	int n,m;
	cin>>n>>m;
	int num[n+5];
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
	}
	sort(num+1,num+n+1);
	cout<<num[n-2]; 
	return 0;
}
