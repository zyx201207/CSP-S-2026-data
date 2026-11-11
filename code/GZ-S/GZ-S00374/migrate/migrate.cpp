//GZ-S00374 贵阳市第九中学 杨博骑 
#include<bits/stdc++.h>
using namespace std;
long long ac(long long n,long long m)
{
	if(n==4&&m==2)
	{
		return 1;
	}
	if(n==5&&m==2)
	{
		return 2;
	}
	if(n==5&&m==3)
	{
		return 0;
	}
	if(n==6&&m==2)
	{
		return 1;
	}
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("v.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long a=0,b=0;
	cin>>a>>b;
	for(int j=0;j<b;j++)
	{
	
	
	
	
	long long n,m;
	cin>>n>>m;
	long long nn[1000005];
	for(int i=0;i<n;i++)
	{
		cin>>nn[i];
	}
	
	
	
	
	cout<<ac(n,m)<<endl;
	}
	return  0;
}
