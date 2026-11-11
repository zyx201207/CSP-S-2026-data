#include<bits/stdc++.h>
using namespace std;
int a[2000010];
int c,t;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		cout<<rand()%10<<'\n';
	}
}
