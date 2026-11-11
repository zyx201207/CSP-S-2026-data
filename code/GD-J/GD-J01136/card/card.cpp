#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[500000+10],b[500000+10],f[300000+10];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			b[j]=a[j];
		}
	    for(int j=i;j<=n;j++)
	    {
	    	int t=0;
	    	for(int k=i;k<=j-1;k++)
	    	{
	    		if(b[k]==b[j]){
	    			t=1;
				}
				if(t==1){
					b[k]=-1;
				}
			}
		}
		for(int j=i;j<=n;j++)
		{
			if(b[j]!=-1)f[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",f[i]);
	}
	return 0;
}
