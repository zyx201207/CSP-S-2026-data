#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[500001],c[500001];;
int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	cin >> a[i];
	for(int i=1;i<=n;i++)
	{
		
		for(int j=i;j<=n;j++)
		{
			int len =1,bj=1;
			while(c[len]!=0) len++;
			for(int k=1;k<=len;k++)
			{
				if(c[i]==a[i]){
					bj=i;
				}
			}	
			if(bj==0)c[len]=a[i];
			else 
			for(int k=bj+1;k<=len;k++)
			c[k]=0;
		}
		int j=1;
		while(c[j]!=0)
		{
			b[c[j]]++;
			j++;
		}		
	}
	for(int i=1;i<=m;i++)
	cout << b[i] << " ";	
	return 0;
}
