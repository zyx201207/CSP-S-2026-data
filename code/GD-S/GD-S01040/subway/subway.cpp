#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int a[m+2];
	int f[n+2][m+2];
	memset(a,0,sizeof(a));
	memset(f,0,sizeof(f));
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	int k,w,t;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>w>>t;
			f[i][w]=t;
		}
	}
	int x,y;
	while(q--){
		ans=0;
		cin>>x>>y;
		ans+=a[x];
		for(int i=1;i<=n;i++){
			if(f[i][x]&&f[i][y]){
				ans+=f[i][x];
				ans+=f[i][y];
			}
		}
		ans+=a[y];
		cout<<ans<<endl;
	}
	
	return 0;
} 
