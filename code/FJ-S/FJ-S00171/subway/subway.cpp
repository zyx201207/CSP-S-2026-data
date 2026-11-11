#include <bits/stdc++.h>

using namespace std;
int w[500005],t[505][50005],cnt[505],dian[505][2005],ans=INT_MAX;
bool num[500005][505];
bool id[500005];
int x,y;
int c,n,m,d,q;
void as(int ID,int s,int xian){
	id[ID]=1;
	if(ID==y){
		ans=min(ans,s);
		return ;
	}
	for(int j=1;j<=n;j++){
		if(num[ID][j]==1&&j!=xian){
			for(int i=1;i<=cnt[j];i++){
				if(id[dian[j][i]]==0){
					as(dian[j][i],s+t[j][ID]+t[j][dian[j][i]],j);
					id[dian[j][i]]=0;
				}
			}
		}else if(j==xian){
			for(int i=1;i<=cnt[xian];i++){
				if(id[dian[xian][i]]==0){
					as(dian[xian][i],s+t[xian][dian[xian][i]],xian);
					id[dian[j][i]]=0;
				}
			}
		}
	}	
	return ;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>cnt[i];
		for(int j=1;j<=cnt[i];j++){
			int a,b;
			cin>>a>>b;
			num[a][i]=1;
			dian[i][j]=a;
			t[i][a]=b;
		}
	}
	while(q--){
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			if(num[x][i]==1){
				as(x,w[x]+w[y]+t[i][x],i);
			}
		}				
		for(int i=1;i<=m;i++){
			id[i]=0;
		}
		cout<<ans<<"\n";
		ans=INT_MAX;
	}
}


