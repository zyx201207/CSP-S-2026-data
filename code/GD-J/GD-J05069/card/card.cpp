#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card1.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cout<<max(i,n/i);
	} 
	return 0;
} 
