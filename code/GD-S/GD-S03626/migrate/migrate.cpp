#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long a[100005];
int main()
{
	freopen("crysta.in","r",stdin);
	freopen("crysta.out","w",stdout);
	cin>>c>>t;
	int sum=1;
	for(int i=1;i<=t;i++)
	{
		sum=1;
		cin>>n>>d;
		fill(a,a+n,0);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int j=n;j<=1;j--)
		{
			sum+=j;
		}
		if(n==1) cout<<0<<endl
		else if(n==2) cout<<0<<endl;
		else cout<<sum/2+1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
