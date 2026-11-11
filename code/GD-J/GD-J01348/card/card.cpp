#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
			for(int k=i;k<j;k++)
				if(b[k]==b[j])
				{
					for(int l=k;l<j;l++)
						b[l]=0;
					break;
				}
		for(int j=i;j<=n;j++)
			if(b[j]!=0) ans[b[j]]++;
			else b[j]=a[j];
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
