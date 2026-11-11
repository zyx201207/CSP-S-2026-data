#include<bits/stdc++.h>
using namespace std;	
int n,m,a[3005],c[3005],num[3005];
bool b[3005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) a[j]=c[j],b[j]=0;
		int z=1;
		for(int j=i;j<=n;i++) {
			if(b[a[j]]==0) b[a[j]]=1;
			else do{
				a[j-z]=-1;
				z++;
			}while(a[j]!=a[j-z]) ;
		}
		for(int j=i;j<=n;j++) num[a[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<num[i]<<" ";
	return 0;
}

