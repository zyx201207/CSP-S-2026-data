#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=505;
const int M=10005;
const ll INF=1e18;

int w[M];  // <1e9
int k[N];
ll dist[M][M];
vector<int> a[N];
vector<int> t[N]; //  t<1e9



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	
	int c,n,m,d,q;
	
	
	cin>>c>>n>>m>>d>>q;
	//cerr<<n<<m<<d<<q;
	
	for(int i=0;i<m;i++)
	
		for(int j=0;j<m;j++){
			if(i!=j) dist[i][j]=INF;
			else dist[i][j]=0;
	}
	
	
		
	for(int i=1;i<=m;i++) cin>>w[i];
	
	//cerr<<(n==2)<<" ";
	
	for(int i=0;i<n;i++){
		//cerr<<'.'<<i;
		cin>>k[i];
		
		for(int j=0;j<k[i];j++){
			int a1,t1;cin>>a1>>t1;
			//cerr<<"a"<<a1<<" "<<t1<<'\n';
			a[i].push_back(a1);
			t[i].push_back(t1);
		}
		//cerr<<'.'<<i;
		for(int j=0;j<k[i];j++){
			for(int h=0;h<k[i];h++){
				dist[a[i][j]][a[i][h]]=min(dist[a[i][j]][a[i][h]],(ll)t[i][j]+t[i][h]);
				///cerr<<a[i][j]<<" "<<a[i][h]<<" "<<dist[a[i][j]][a[i][h]]<<"\n";
			}
			//cerr<<'.'<<i;
		}
		//cerr<<'.'<<i;
	}
	
	for(int h=0;h<m;h++)
		for(int i=0;i<m;i++)
			for(int j=0;j<m;j++)
				dist[i][j]=min(dist[i][j],dist[i][h]+dist[h][j]);
			
	
	for(int r=0;r<q;r++){
		int x,y;cin>>x>>y;
		cout<<dist[x][y]+w[x]+w[y]<<'\n';
	}
	
	return 0;
}

