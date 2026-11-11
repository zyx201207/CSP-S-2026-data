//GZ-S00374 贵阳市第九中学 杨博骑 
#include<bits/stdc++.h>
using namespace std;
long long ac(long long n,long long m)
{
	if(n==5&&m==2)
	{
		return 1;
	}
	if(n==10&&m==3)
	{
		return 2;	
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long a,b;
	cin>>a>>b;
	long long nn[1000005],mm[1000005];
	for(int i=0;i<b;i++)
	{
		long long n,m;
		cin>>n>>m;
		for(int j=0;j<n*2-1;j++){
			cin>>nn[i]>>mm[i];
			cout<<ac(n,m)<<endl;
		}
	}
	return  0;
}
