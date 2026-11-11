#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[550],x,y;
int ans;
int w[500010];
bool to[510][200010];
struct node{
	int bh,t;
}a[510][500010];
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
			cin>>a[i][j].bh>>a[i][j].t;
			to[i][a[i][j].t]=1;
		}
	}
	while(q--){
		ans=0;
		cin>>x>>y;
		if(x==y){
			cout<<0<<endl;
			continue;
		}
		ans+=w[x]+w[y];
		bool b=0;
		for(int i=1;i<=n;i++){
			int bj=0,cnt=0;
			for(int j=1;j<=k[i];j++){
				if(a[i][j].bh==x){
					bj++;
					cnt+=a[i][j].t;
				}
				if(a[i][j].bh==y){
					bj++;
					cnt+=a[i][j].t;
				}
			}
			if(bj==2){
				b=1;
				if(i==1) ans+=cnt;
				else ans=min(ans+cnt,w[x]+w[y]+cnt);
			}
		}
		if(b==0){
			for(int i=1;i<=n;i++){
				if(to[i][x]==1){
					int cnt=500010;
					for(int j=1;j<=n;j++){
						if(to[j][y]==1){
							for(int z=1;z<=k[i];z++){
								for(int f=1;f<=k[i];f++){
									if(to[i][a[i][z].t]==1&&to[i][a[i][f].t]==1){
										cnt=min(a[i][z].t+a[i][z].t,cnt);
									}
								}
							}
						}
					}
					if(i==1) ans+=cnt;
					else ans=min(ans,cnt+w[x]+w[y]);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
