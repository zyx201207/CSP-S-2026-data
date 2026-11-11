#include<bits/stdc++.h>
using namespace std;

int c,t,n,d;
long long noo[1000],doo[1000],arr[1000][1000],foo[1000][1000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>noo[i]>>doo[i];
		for(int j=1;j<=noo[i];j++)
		{
			cin>>arr[i][j];
		}
	}
	for(int i=1;i<=t;i++)
	{
		for(int j=1;j<noo[i];j++)
		{
			for(int k=j+1;k<=noo[i];k++)
			foo[j][k]=0;
		}
	    for(int j=1;j<=noo[i];j++)
		{
			for(int k=j+1;k<=j+doo[i]&&k<=noo[i];k++)
			foo[j][k]=1;
		}	
		for(int j=1;j<=noo[i];j++)
		{
			for(int k=j+doo[i]+1;k<=noo[i];k++)
			{
				foo[j][k]=foo[j+d][k]+1;
	           	for(int e=d-1;e>=1;e--)
	         	{
	         			foo[j][k]=min(foo[j][k],foo[j+e][k]+1);
	           	}
			}
		}
		cout<<foo[1][noo[i]]<<endl;
	} 
	return 0;
}
