#include<bits/stdc++.h>
using namespace std;
int n,m; 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
   //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
	cin>>n>>m;
	int f[n+1],a[n+1],cnl=0,flag=1,f1[n+1],ans[n+1];
	for(int i=1;i<=n;i++)ans[i]=0;
	for(int i=1;i<=n;i++){
		cin>>f[i];
		f1[i]=f[i];
		}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int k=1;k<=cnl;k++)
			{
				if(a[k]==f[j])f[j]=0,flag=0                                      ;
			    if(flag==0)a[k]=0;
			}
			cnl++;
			a[cnl]=f[j];
			flag=1;
		}
		for(int i=1;i<=m;i++)ans[a[i]]++;
		for(int i=1;i<=n;i++)a[i]=0;
		for(int i=1;i<=n;i++)f[i]=f1[i];
		cnl=0;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";		
    return 0;
}
