#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("card.in","r","stdin");
	//freopen("card.out","w","stdout");
	 int n,m,sum;
	 int a[500005][500005];
	 cin>>n>>m;
	 
	 for(int i=1;i<=n;i++)
	 {
	 	for(int j=1;j<=m;j++)
	 	{
	 		cout<<a[i][j];
		 }
	 }
	 sum=0;
	 for(int i=1;i<=n;i++)
	 {
	 	for(int j=1;j<=m;j++)
	 	{
	 		sum+=a[i][j];
	 		sum++;
		 }
	 }
	 cout<<sum;
}
