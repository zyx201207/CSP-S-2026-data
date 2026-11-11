#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,dx,dy;
unsigned long long w[500003];
int g[503][503];
unsigned long long ans;
int a,t;
unsigned long long k,x,y,tx,ty;
vector<int> s[500003];
vector<int> l[500003];
int dp[100003][503];
bool p[100003][503];
void dfs(int fa,int qi,int zo,unsigned long long ti){
	
	if(qi==zo){
		ans=min(ans,ti);
		return;
	} 
	
	if(dp[fa][qi]<=ti&&dp[fa][qi]!=0) return;
	dp[fa][qi]=ti;
	
	for(int i=1;i<=n;i++){
		
		if(i!=qi&&g[i][qi]!=0&&p[fa][i]==0){
	//		cout<<qi<<" "<<i<<endl;
			p[fa][i]=1;
			dfs(fa,i,zo,g[i][qi]+ti);
			p[fa][i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			s[a].push_back(i);
			l[a].push_back(t);
			for(int r=0;r<s[a].size()-1;r++){
				if(g[i][s[a][r]]!=0)g[i][s[a][r]]=g[s[a][r]][i]=min(g[s[a][r]][i],l[a][r]+t);
				else g[i][s[a][r]]=g[s[a][r]][i]=l[a][r]+t;
			}	
		}
	}
	
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		tx=w[x];
		ty=w[y];
		ans=1e19;
		for(int j=0;j<s[x].size();j++){
			dx=s[x][j];
			tx+=l[x][j];
			p[i][dx]=1;
			
			for(int r=0;r<s[y].size();r++){
				dy=s[y][r];
				ty+=l[y][r];
				if(c<=19&&c>=12){
					int ti=ty+tx;
					
				}else dfs(i,dx,dy,tx+ty);
				ty-=l[y][r];
			}
			tx-=l[x][j];
			p[i][dx]=0;
		}
		cout<<ans<<endl;
	}
	return 0;
}
