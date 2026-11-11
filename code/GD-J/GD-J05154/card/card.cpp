#include<bits/stdc++.h>
using namespace std;
long long n,m,a[30005],b[30005],cc,c[30005],f;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cc=0;
		for(int j=i;j<=n;j++)
		{
			if(cc==0) cc++,b[cc]=a[j];
			else{
				f=0;
				for(int k=1;k<=cc;k++)
				{
					if(b[k]==a[j])
					{
						f=1;
						cc=k;
					}
				}
				if(f==0) cc++,b[cc]=a[j];
			}
		}
		for(int i=1;i<=cc;i++)
		{
			c[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
