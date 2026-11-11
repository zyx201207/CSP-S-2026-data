#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500005],k[505],a[505][500005],f[505][50005],ans=-1,o;
signed main(){
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>c>>n>>m>>d>>q>>o;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=m;i++){
    	for(int j=1;j<=m;j++)
    	{
    		if(i!=j)f[i][j]=1e18; 
		}
	}
    for(int i=1;i<=n;i++)
    {
    	cin>>k[i];
    	for(int j=1;j<=k[i];j++)cin>>a[i][j]>>f[i][j];
    	for(int j=1;j<k[i];j++){
    		f[a[i][j]][a[i][j+1]]=min(f[a[i][j]+a[i][j+1]);
		}
    }
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		if(i==j)continue;
    		for(int o=1;o<=k[i];o++){
    			for(int p=1;p<=k[j];p++){
    				if(a[i][o]==a[j][p])
    				f[a[i][o]a[j][p]]=min(f[a[i][o-1]+a[j][p+1]]);
				}
			}
		}
	}
	while(q--)
	{
		int x,y;cin>>x>>y;
		cout<<s[x][y]+w[x]+w[y]<<"\n";                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
	}
	return 0;
}
