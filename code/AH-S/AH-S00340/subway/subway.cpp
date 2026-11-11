#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int w[100],bh,time[4][100],b[4][100],k,x,y;
bool p[4][100];
vector<int>edge[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T,n,m,d,q,t;
	cin>>T>>n>>m>>d>>q;
	if(T>=0&&T<=3){
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			cin>>t;
			while(t--){
				cin>>bh>>k;
				p[i][bh]=1;
				time[i][bh]=k;
			}
		}
		for(int i=1;i<=m;i++){
			time[1][i]+=time[1][i-1];
			time[2][i]+=time[2][i-1];
			time[3][i]+=time[3][i-1];
		}
		while(q--){
			cin>>x>>y;
			int ans=INT_MAX;
			if(n==1){
				ans=time[1][y]-time[1][x-1]+w[x]+w[y];
			}
			else if(n==2){
				if(p[1][x]==1&&p[1][y]==1)ans=min(ans,time[1][y]-time[1][x-1]+w[x]+w[y]);
				if(p[2][x]==1&&p[2][y]==1)ans=min(ans,time[2][y]-time[2][x-1]+w[x]+w[y]);
				for(int i=x+1;i<=y-1;i++){
					if(p[1][x]==1&&p[1][i]==1&&p[2][i]==1&&p[2][y]==1)ans=min(ans,time[1][i]-time[1][x-1]+time[2][y]-time[2][i-1]+w[x]+w[y]);
					if(p[2][x]==1&&p[2][i]==1&&p[1][i]==1&&p[1][y]==1)ans=min(ans,time[2][i]-time[2][x-1]+time[1][y]-time[1][i-1]+w[x]+w[y]);
				}
			}
			else{
				if(p[1][x]==1&&p[1][y]==1)ans=min(ans,time[1][y]-time[1][x-1]+w[x]+w[y]);
				if(p[2][x]==1&&p[2][y]==1)ans=min(ans,time[2][y]-time[2][x-1]+w[x]+w[y]);
				if(p[3][x]==1&&p[3][y]==1)ans=min(ans,time[3][y]-time[3][x-1]+w[x]+w[y]);
				for(int i=x+1;i<=y-2;i++){
					for(int j=i+1;j<=y-1;j++){
					if(p[1][x]==1&&p[1][i]==1&&p[2][i]&&p[2][j]==1&&p[3][j]==1&&p[3][y]==1)ans=min(ans,time[1][i]-time[1][x-1]+time[2][j]-time[2][i-1]+time[3][y]+time[3][j-1]+w[x]+w[y]);
					}
				}
			}
			cout<<ans;
		}
		return 0;
	}
	return 0;
}
