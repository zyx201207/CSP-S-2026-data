#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);\
	int n;
	cin>>n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cout<<(i*n-1)%11<<endl;
	}
	return 0;
} 
