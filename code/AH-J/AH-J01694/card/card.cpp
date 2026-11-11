#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int a[N],p[N],c[N],ans[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(p,0,sizeof(p));
		memset(c,0,sizeof(c));
		int cnt=0;
		for(int j=i;j<=n;j++)
		{
			if(p[a[j]]){
				for(int k=cnt;k>=1;k--)
				{
					if(c[k]==a[j]){
						c[k]=-1;
						break;
					}
					else {
						p[c[k]]=0;
					    c[k]=-1;
					}
				}
			}
			c[++cnt]=a[j];
			p[a[j]]=1;
		}
		for(int j=1;j<=m;j++)
		    if(p[j])ans[j]++;
	}
	for(int i=1;i<=m;i++)
	    cout<<ans[i]<<" ";
	return 0;
}
