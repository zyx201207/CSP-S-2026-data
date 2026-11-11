#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,s,n,m,a[100010];
	cin>>c>>s;
	while(s--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		cout<<n*(n-1)/2<<endl;
	}
	
	return 0;
} 
