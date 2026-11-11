#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long n,m,c=0;
	cin>>n>>m;;
	int d[m+1],f[m+1];
	int mj[m+1];
	for(int i=1;i<=m;i++)
	{
		c=0;
		cin>>d[i]>>f[i];
		int s[d[i]][2];
		for(int j=1;j<d[i];j++)
		{
			for(int h=1;h<=2;h++)
			{
				cin>>s[j][h];
			}
		}
		c=f[i]*3;
		if(d[i]==f[i])
		{
			mj[i]=0;
			continue;
		}
		if(c>=d[i])
		{
			mj[i]=1;
		}
		else
		{
			mj[i]=d[i]-c+1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<mj[i]<<endl;
	}
	
	return 0;
}
