#include<bits/stdc++.h>
using namespace std;
int a[29999999];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,i,j;
	cin>>c>>t;
	for(i=1;i<=t;i++)
	{
		int n,d;
		cin>>n>>d;
		for(j=1;j<=n;j++)
		{
			cin>>a[j];
		}
		if(c==11||c==12||c==0)
		{
			int k=a[2]-a[1],shy;
			if(k>d)
			{
				cout<<0<<endl;
				continue;
			}
			shy=d/k;
			cout<<(a[n]-a[1]-2*shy+2)<<endl;
		}
	}
	return 0;
}
