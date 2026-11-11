#include <bits/stdc++.h>
using namespace std;
int m,n;
long long a1[2000],xz=0;
long long a2[2000][20];	
int sum[20];
void asd(int x,long long y)
{   int z=1;
	for(int i=1;i<=20;i++) z*=2;
	for(int i=20;i>=0;i--)
	{
		a2[x][i]=y/z;
		y-=z;
		z/=2;
	}
}
void ans(int y)
{

	for(int i=1;i<=20;i++)
	{
		if(sum[i]==1&&a2[y][i]==1) sum[i]=1;
		else sum[i]=0;
	}
}
void fy(){
	int zz=1;
	for(int i=1;i<=20;i++) xz+sum[i]*zz;
	zz*=2;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a1[i];
		asd(i,a1[i]);
	}
	if(m==1){
		sort(a1+1,a1+n);
		cout<<a1[n];
	}
	else if(m==n){
		for(int i=1;i<=20;i++) sum[i]=a2[1][i];
		for(int i=2;i<=20;i++) ans(i);
		cout<<xz;
	}
	else{
		sort(a1+1,a1+n);
		cout<<a1[n/2];
	}
	return 0;
}
