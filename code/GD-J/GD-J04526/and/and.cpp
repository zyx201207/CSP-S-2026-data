#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2e5+10;
long long f[N];
long long w[N];
int main()
 {
 	freopen("and.in","r",stdin);
 	freopen("and.out","w",stdout); 
 	int n,m;
 	cin>>n>>m;
 	for(int i=0;i<n;i++)
 	{
 		scanf("%lld",&w[i]);
	 }
	 for(int i=0;i<n;i++)f[1]=max(f[1],w[i]);
	 for(int i=0;i<n;i++)
	 {
	 	bool flag=false;
	 	for(int j=m;j>=0;j--)
	 	{
	 		f[j]=max(f[j],f[j-1]&w[i]);
	 		if(flag)
	 			f[j]=max(f[j],f[j-1]&w[i]);
	 		else
	 		{
	 			f[j]=f[j-1]&w[i];
	 			flag=1;
	 		}
	 	}
	}
	printf("%lld",f[m]); 
	 
 }



