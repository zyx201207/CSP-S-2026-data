#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],s,f[300010],v[300010];
void mj()
{
	for(int i=1;i<=n;i++)
	{
		f[b[i]]++;
	}
} 
void qk()
{
	for(int i=1;i<=n;i++)v[i]=0,b[i]=0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int w=2;w<=2;w++)
	{
		s=w;
		for(int i=w;i<=n;i++)
		{
			if(v[a[i]]==0)
			{
				b[s]=a[i];
				v[a[i]]=i;
			}
			else
			{
				for(int j=v[a[i]]+1;j<s;j++)
				{
					v[a[j]]=0;
					b[j]=0;
				}
				s=v[a[i]];
			}
			s++;
		}
		mj();
		qk();
	}
	
	for(int i=1;i<=m;i++)
	{
		cout<<f[i]<<" "; 
	}
	return 0;
} 
