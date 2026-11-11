#include<bits/stdc++.h>
using namespace std;

int num[20002];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
	}
	if(m%2==0) cout<<n+1;
	else cout<<n;
	
	return 0;
}
