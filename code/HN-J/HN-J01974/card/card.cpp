#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	int a[n+10]={0};
	int tp[m+10]={0},pz[n+10]={0};
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		pz[n+10]={0};
		for(int j=i;j<=n;j++)
		{
			bool f=false;
			for(int k=1;k<=n;k++)
				if(a[j]==pz[k])
					f=true;
			if(f==false)
				pz[j]=a[j];
			else{
				for(int k=j;k<=n;k++)
					pz[k]=0;
			}
		}
		bool f=false;
		for(int l=1;l<=n;l++){
			if(pz[l]==i)
				tp[i]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<tp[i]<<" ";
	return 0;
} 
