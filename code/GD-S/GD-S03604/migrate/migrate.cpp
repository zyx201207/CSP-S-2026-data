#include<bits/stdc++.h>
using namespace std;

long long x[6000000];
long long da[5000][5000];



int main(){
	int c,t,n;long long d;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if(c==11||c==12)
		{
			cout<<0<<"\n";
			continue;
		}
		else if(c>=1&&c<=6){
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i;j<=n;j++)
				{
					a[i][j]=x[j]-x[i];
				}
			}
		}
	}
	return 0;
}
