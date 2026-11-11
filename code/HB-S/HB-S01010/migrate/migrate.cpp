#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000005],ans=0,nm;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		ans=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>x[j];
		}
		for(int k=1;k<=n;k++)
		{
			
			int j=k+3;
			if(j>n) break;
			if(x[j]-x[k]<=d*2&&x[j]-x[k]>d) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
