//GZ-S00379 刘祚诚 北京师范大学贵阳附属中学 
#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;
int w[N],dis[N][N],a[N],t[N];
int c,n,m,d,q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m+n;i++){
		dis[i][i]=0;		
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int t;
			cin>>a[j]>>t;
			dis[a[j]][400+j]=dis[400+j][a[j]]=t;
			dis[a[j]][a[j-1]]=dis[a[j-1]][a[j]]=dis[a[j]][400+j]+dis[a[j-1]][400+j-1];
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(dis[i][j]!=0){
					dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[j][k]);
				}else{
					dis[i][j]=dis[j][i]=dis[k][i]+dis[k][j];
				}
			}
		}
	}
	while(q--){
		int i,j;
		cin>>i>>j;
		int ans=0;
		ans+=dis[i][j]+w[i]+w[j];
		cout<<ans<<endl;
	}
	return 0;
}
