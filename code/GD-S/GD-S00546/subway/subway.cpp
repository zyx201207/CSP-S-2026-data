#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int v[505][500005];
struct p_1{
	int x,y;
}v_2[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			v[i][x]=y;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		int ans=0;
		cin>>x>>y;
		ans+=w[x]+w[y];
		v_2[i].x=x;
		v_2[i].y=y;
		for(int j=1;j<=n;j++){
			for(int r=1;r<=m;r++){
				if(v[j][r]==x){
					ans+=v[j][r];
				}
				if(v[j][r]==y){
					ans+=v[j][r];
				}
			}
		}
		cout<<ans<<endl;
	}
}
