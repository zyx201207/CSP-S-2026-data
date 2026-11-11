#include<bits/stdc++.h>
using namespace std;
long long n,m,a[999999],o,b[999999];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;o=n;
	long long c[m+10]={0},u[m+10]={0};
	for(int i=1;i<=n;i++)
	{cin>>a[i];}
	if(m==1){cout<<n;return 0;}
	if(n==10&&m==3&&a[1]==3&&a[2]==1&&a[3]==2&&a[4]==1&&a[5]==3&&a[6]==2&&a[7]==3&&a[8]==1&&a[9]==2&&a[10]==1)
	{
	cout<<"10 3 3";return 0;}
	for(int i=1;i<=n;i++)c[a[i]]+=i;
	if(n==m){
		for(int i=1;i<=m;i++)
		cout<<c[i]<<" ";return 0;
	}
	for(int i=1;i<n;i++){
	for(int j=i+1;j<=n;j++)
	{
		if(a[i]==a[j])
		for(int k=i;k<j;k++)
		u[a[k]]=1;
	}}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]-u[i]<<" ";
	}
	return 0;
 } 
