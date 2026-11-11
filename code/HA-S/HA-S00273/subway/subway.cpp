#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;//n为地铁线数，m为地铁站数
//d为每个站最多几个线,q为询问次数 
int w[500005];
struct node{
	int tai[25],cnt,tim[25];
}f[500005];
int zhuan[505][505];
int work(int x,int y){
	int sum=1e16;
	for(int i=1;i<=f[x].cnt;i++){
		for(int j=1;j<=f[y].cnt;j++){
			int bii=zhuan[f[x].tai[i]][f[y].tai[j]]+f[x].tim[i]+f[y].tim[j];
			sum=min(sum,bii);
		}
	}
	return sum+w[x]+w[y];
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int v,tim;cin>>v>>tim;
			f[v].tim[++f[v].cnt]=tim;
			f[v].tai[f[v].cnt]=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			zhuan[i][j]=1e16+7;
			if(i==j)zhuan[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		if(f[i].cnt>1){
			for(int j=1;j<=f[i].cnt;j++){
				for(int ji=1;ji<=f[i].cnt;ji++){//从j线转到ji线 
					if(j==ji)continue;
					int bi=f[i].tim[j]+f[i].tim[ji];//cout<<bi<<endl;
					zhuan[f[i].tai[j]][f[i].tai[ji]]=min(zhuan[f[i].tai[j]][f[i].tai[ji]],bi);
					zhuan[f[i].tai[ji]][f[i].tai[j]]=zhuan[f[i].tai[j]][f[i].tai[ji]];
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(zhuan[i][j]>zhuan[i][k]+zhuan[k][j]){
					zhuan[i][j]=zhuan[i][k]+zhuan[k][j];
					zhuan[j][i]=zhuan[i][j];
				}
			}
		}
	}
	while(q--){
		int xx,yy;cin>>xx>>yy;
		cout<<work(xx,yy)<<"\n";
	}
	return 0;
} 
