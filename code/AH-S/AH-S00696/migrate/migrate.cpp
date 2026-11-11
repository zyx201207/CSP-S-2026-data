#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[200005],q[2000005],sum[200005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t>>c;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			q[i]=x[i]-x[i-1];
		}
		if(c==11||c==12)
		{
			long long p=q[2];
			if(p*2>d||((d/p)%2==0)) cout<<0<<endl;
			else
			{
				cout<<(x[n]-x[1])/p<<endl;
			}
		}
		else
		{
			cout<<0<<endl;
		}
	}
	return 0;
}
