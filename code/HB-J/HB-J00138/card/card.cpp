#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int bigv[300005];
int main()
{
	freopen("card.out","w",stdout);
	freopen("card.in","r",stdin);
	scanf("%d %d",&n,&m);
	
		int v[300005]={0};
		int s[500005]={0};
		int l=0;
		for(int i=f;i<=n;i++)
		{
			if(!a[i]) continue;
			if(!v[a[i]])
			{
				if(a[i])
				{
					l++;
					s[l]=i;
					v[a[i]]=l;
				}
			}
			else
			{
				if(a[i]&&l>0)
				{
					int nl=v[a[i]];
					a[s[nl]]=0;
					for(int x=v[a[i]];x<=l;x++)
					{
						v[s[x]]=0;
						s[x]=0;
					}
					l=nl;
					s[l]=i;
					v[a[i]]=l;
				}
			}
			//for(int i=1;i<=n;i++) cout<<(s[i])<<" ";
		}
		//cout<<"\n";
		for(int i=1;i<=m;i++) bigv[i]+=(v[i]?1:0);
	}
	for(int i=1;i<=m;i++) cout<<bigv[i]<<" ";
	return 0;
}
