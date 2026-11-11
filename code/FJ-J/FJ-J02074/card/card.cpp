#include<bits/stdc++.h>
using namespace std;
int n,m,a[20],c[20],d[20];
bool b[20];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
		cin>>d[i];
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		for(int r=1;r<=n;r++)
			a[r]=0;
		for(int r=n;r>=i;r--)
			a[r]=d[r];
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]==0)
			{
				b[a[j]]=1;
				c[a[j]]++;
			}
			else
			{
				for(int p=j-1;p>=1;p--)
				{
					if(a[p]!=a[j])
					{
						c[a[p]]--;
						a[p]=0;
					}
					else
						break;
				}
				a[j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	return 0;
}
