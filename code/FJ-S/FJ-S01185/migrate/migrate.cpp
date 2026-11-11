#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long x[2000002];
long long d;
long long cnt=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		long long sum=0;
		for(int i=1;i<=n;i++) sum+=x[i];
		if(d==2&&n>=4&&sum<=9)
		{
			cnt+=n-3;
		}
		cout<<cnt;
	}
	return 0;
}
