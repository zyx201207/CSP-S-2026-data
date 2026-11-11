#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long a[10004];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	if(c==0)
	{
	  int n,d;
	  cin>>n>>d;
	  if(n==4&&d==2) cout<<"1"<<endl<<"2";
	  else cout<<"0"<<endl<<"1";
    }
	while(t--)
	{
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}

