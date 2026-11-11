#include<bits/stdc++.h> 
using namespace std;
int a[500002][3],c;
int find1(int j,int z)
{
	if(a[j][2]==0)return 0;
	if(a[z][1]==a[j][1])a[j][2]=a[z][2];
	else find1(j,a[z][2]);
}
int find2(int z)
{
	if(a[z][2]==0)return 0;
	else
	{
		c++;
		find2(a[z][2]);
	}
} 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i][1];
    for(int i=1;i<=n;i++)
    {
    	for(int j=i;j<=n;j++)
    	{
    		a[j][2]=j-1;
    		find1(j,j-1);
		}
	 find2(n);
	 cout<<c<<" ";
	}
	return 0; 
} 
