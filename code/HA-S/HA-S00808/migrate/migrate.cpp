#include<bits/stdc++.h>
using namespace std;
long long s[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	int n,d;
	cin>>c>>t;
	int ls;
	int res=0;
	int lst;
	while(t--)
	{
		cin>>n>>d;
		for(int i=0;i<n;i++)
		{
			cin>>s[i];
		}
		ls=s[1]-s[0];
		ls=d/ls;
		lst=n-(2*ls);
		res+=lst*(ls-2);		
		res+=(ls*(ls-1))/2;
		cout<<res<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
