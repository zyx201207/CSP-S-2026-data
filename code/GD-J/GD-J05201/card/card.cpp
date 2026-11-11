#include<bits\stdc++.h>
using namespace std;
int i,j,l,k,n,m,s,a[500005],b[500005],c[300005],a1[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		a1[i]=a[i];
	}
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			for(k=i;k<=j-1;k++){
				if(a1[k]==a1[j]){
					for(l=k;l<j;l++)
					a1[l]=0;
				}
			}
		}
		for(j=i;j<=n;j++)
		if(a1[j]!=0&&c[a1[j]]==0)
		b[a1[j]]++,c[a1[j]]=1;
		for(j=1;j<=n;j++)
		a1[j]=a[j],c[a[j]]=0;
	}
	
	for(i=1;i<=m;i++)
	cout<<b[i]<<" ";
}

