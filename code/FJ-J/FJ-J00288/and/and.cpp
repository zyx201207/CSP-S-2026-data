#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("and.in","r","stdin");
freopen("and.out","w","stdout");
int m,n;
cin>>m>>n;
string a[m+2];
for(int i=1;i<=m;i++)
{
	cin>>a[i];
	
}
int y[n+1];
for(int x=1;x<=m;x++)
{
	y[x]=0;
	
}
for(int j=1;j<=m;j++)
{
	while(a[j]==0||a[j]==1)
	{
		a[j]=a[j]/2;
		y[j]=a[j]%2;
	}
}
return 0;
}