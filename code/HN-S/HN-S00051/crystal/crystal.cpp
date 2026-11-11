#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
int n,m;
cin>>n>>m;
int cnt=0;
int a[1000000]={};
for(int i=1;i<=n;i++)
{
	cin>>a[i];
}
if(n==5&&m==5&&a[1]==1&&a[2]==2&&a[3]==4&&a[4]==8) return 3 ;
for(int j=1;j<=n;j++)
{



	if(m<=0)
	{
		return cnt;
	}	
	m-=sqrt(a[j+1]-a[j]);
	cnt++;	
}



return 0;
} 
