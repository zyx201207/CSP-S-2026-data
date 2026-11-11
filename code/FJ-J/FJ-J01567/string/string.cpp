#include<bits/stdc++.h>
using namespace std;
char n[9000005];
int main() 
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int m;
	cin>>m;
	int gs;
	char zm;
	int t=1;
	for(int i=1;i<=m;i++)
	{
		cin>>gs>>zm;
		for(int j=1;j<=gs;j++)
		{
			n[t++]=zm;
		}
	}
	long long ans=0;
	t-=1;
	for(int i=1;i<=(t+1)/2;i++)
	{
		if(n[i]!=n[t-i+1])
		{
			ans++;
			//cout<<n[i]<<" "<<n[t-i+1]<<endl<<endl;
		}
	}
	cout<<ans;
}
