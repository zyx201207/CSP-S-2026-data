#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500001],a[500001][501],t[500001][501],k[501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int r=1;r<=q;r++){
		int x,y,ans=2147483640;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			int f=0,txy;
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x||a[i][j]==y){
					f++;
					txy+=t[i][j];
				}
			}
			if(f==2){
				ans=min(ans,txy);
			}
		}
		cout<<ans<<endl;
	}
}