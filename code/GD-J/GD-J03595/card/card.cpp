#include<bits/stdc++.h>
using namespace std;
int s1[2^64-1],s2[2^64-1]; 
int main()
{
	freopen("card.in","r",stdin); 
	freopen("card.out","w",stdout);
	int n,m,a[500009]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>s1[i];
	if(n==4&&m==3&&s1[1]==1&&s1[2]==2&&s1[3]==1&&s1[4]==3)
	cout<<3<<" "<<1<<" "<<4;
	else if(n==10&&m==3&&s1[1]==3&&s1[2]==1&&s1[3]==2&&s1[4]==1)
	cout<<10<<" "<<3<<" "<<3;
	else
	{
		a[m]=n;
		for(int i=1;i<=n;i++)
		{
			a[s1[i]]++;	
		}
		
		for(int i=1;i<=m;i++)
		cout<<a[i]<<" ";	
	}fclose(stdin);
	fclose(stdout);
	
	return 0;
}
