#include<bits/stdc++.h>
using namespace std;
int read[210000];
bool a[210000][110];
int b[210000];
int m,n,ans;
long long e[33]={886,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
int er(int x,int y,int z)
{
	
	if(x==0)
	{
		b[z]=y;
		return 0;
	}
	a[z][y]=(x%2);
	er(x/2,y+1,z);
}
int bi(int x,int y,int z,int lei)
{
	if(z>max(b[x],b[y]))
	{
		ans=max(ans,lei);
		return 0;
	}
	if(a[x][z]==a[y][z]&&a[x][z]==1)
		lei=lei+e[z];
	bi(x,y,z+1,lei);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>read[i];
		er(read[i],1,i);
	}
	if(m==2)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j)
					bi(i,j,1,0);
	if(m==1)
		for(int i=1;i<=n;i++)
			ans=max(ans,read[i]);
	cout<<ans;
	return 0;
}

