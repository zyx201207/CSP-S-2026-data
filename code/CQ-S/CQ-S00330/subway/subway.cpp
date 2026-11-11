#include <bits/stdc++.h>
using namespace std;
const int MAXN=505,MAXM=5e5+5;
int c,n,m,d,q,w[MAXM],len[MAXM],lin[MAXM][21][2],lmp[MAXN][MAXN];
long long ans[MAXN][MAXN],mp[MAXN][MAXN];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			lin[a][++len[a]][0]=t;
			lin[a][len[a]][1]=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			lmp[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=len[i];j++){
			for(int k=1;k<=len[i];k++){
				lmp[lin[i][j][1]][lin[i][k][1]]=min(lmp[lin[i][j][1]][lin[i][k][1]],lin[i][j][0]+lin[i][k][0]);
			}
		}
	}
	memset(ans,0x3f,sizeof(ans));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(lmp[i][j]==INT_MAX){
				mp[i][j]=-1;
			}
			else{
				mp[i][j]=lmp[i][j];
			}
			if(i==j){
				mp[i][j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				ans[j][k]=min(ans[j][k],ans[j][i]+ans[k][i]);
				if(mp[k][i]!=-1&&mp[j][i]!=-1){
					ans[j][k]=min(ans[j][k],mp[k][i]+mp[j][i]);
				}
				if(mp[k][i]!=-1){
					ans[j][k]=min(ans[j][k],mp[k][i]+ans[j][i]);
				}
				if(mp[j][i]!=-1){
					ans[j][k]=min(ans[j][k],ans[k][i]+mp[j][i]);
				}
			//	cout<<i<<' '<<j<<' '<<k<<" "<<ans[j][k]<<endl;
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		long long lans=1e18;
		for(int j=1;j<=len[x];j++){
			for(int k=1;k<=len[y];k++){
		//		cout<<lin[x][j][1]<<" "<<lin[y][k][1]<<endl;
				lans=min(lans,ans[lin[x][j][1]][lin[y][k][1]]+lin[x][j][0]+lin[y][k][0]);
			}
		}
		cout<<lans+w[x]+w[y]<<'\n';
	}
	return 0;
}
/*
难点在读题。

注意 long long 

绿吧，不到青。 

哦，可能有青吧，毕竟看起来多少得写点。 

忘了floyd咋打了，管他的，打个dij。 

不不不，打dij会T，想想…… 
*/
