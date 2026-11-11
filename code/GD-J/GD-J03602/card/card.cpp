#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	long long a,b,c[1000000],c1[1000000],d[1000000],x=0,y=0;
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			d[y+j]=c[j];
			x=j-1;
			for(int l=1;l<j;l++){
				if(d[y+j]==d[y+l]){
					y+=j;
					j=a+1;
					l=j+1;
				}
			}
		}
		for(int j=y;j<=y+x;j++){
			c1[d[j]]++;
		}
	}
	for(int i=1;i<=b;i++)
	{
		cout<<c1[i]<<" ";
	}
	
	return 0;
 } 
