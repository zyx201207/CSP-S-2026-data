#include<bits/stdc++.h>
using namespace std;
const long long N=150; 
long long c,n,m,d,q,a[N],k[N],f[N],x,y,z,s[500],h[50][50],b[50][50];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++) 
    {
    	cin>>z;
    	for(int j=1;j<=z;j++)	cin>>k[j]>>f[j];
    	for(int j=1;j<=z;j++)
    	{
    		for(int g=1;g<=j;g++)
    		{
    			if(j!=g)
    			{
    				h[k[j]][k[g]]=1;
    				h[k[g]][k[j]]=1;
    				b[k[j]][k[g]]=f[j];
    				b[k[g]][k[j]]=f[j];
				}
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		cout<<b[x][y]+a[x]+a[y]+b[y][x]<<"\n";
	}
	return 0;
 } 




