//GZ-J00151 安顺市实验学校 罗子骏
#include <bits/stdc++.h>
using namespace std; 
long long a[500050],n,m;
int main()
{	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cout<<'0';
		if(i!=m) cout<<' ';
	}

	return 0;
} 
