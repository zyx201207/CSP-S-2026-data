#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;	
int c,n,m,d,q;
int w[1005];
int a[1005][1005],t[1005][1005],ans=0,k[1005];
int x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//cout<<35<<endl<<16;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int tt;
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		cin>>x>>y;
		ans=w[x]+w[y];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x || a[i][j]==y){
					ans+=t[i][j];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
