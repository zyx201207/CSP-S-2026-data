#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long n,m,c=0;
	cin>>n>>m;
	int d[m+1],f[m+1];
	for(int i=1;i<=m;i++)
	{
		c=0;
		cin>>d[i]>>f[i];
		int s[d[i]];
		for(int j=1;j<=d[i];j++)
		{
			cin>>s[j];
		}
		for(int h=1;h<=d[i]-3;h++)
		{
			for(int j=h+3;j<=d[i];j++)
			{
				if(s[j]-s[j-1]==s[j-1]-s[h+1]==s[h+1]-s[h]&&s[j-1]-s[h]<=f[i]&&s[j]-s[h]>f[i])
				{
					c++;
				}
			}
		}
		cout<<c<<endl;
	}
	
	return 0;
}
