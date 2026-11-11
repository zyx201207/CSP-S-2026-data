#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define out() (cout<<"sb\n")
#define vector basic_string
#define pii pair<int,int>
#define fi first
#define se second

const int N=505,M=5e5+5,D=25; 
const int inf=0x3f3f3f3f3f3f3f3f;

//bool beg;

int lcx,n,m,d,q;
int w[M],f[N][N];
vector<pii> v[M]; //fi:id,se:t

//bool en;

signed main(){
//	system("fc subway.in subway.ans");
//	cerr<<((&en)-(&beg))/1048576<<"\n";
//	system("size subway.exe"); 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	IOS;
	cin>>lcx;
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int len;
		cin>>len;
		for(int j=1;j<=len;j++){
			int x,t;
			cin>>x>>t;
			v[x]+=(pii){i,t};
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0; //自己肯定是 0 
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			for(int k=j+1;k<v[i].size();k++){
				int p1=v[i][j].fi,p2=v[i][k].fi;
				int v1=v[i][j].se,v2=v[i][k].se;
				f[p1][p2]=f[p2][p1]=min(f[p1][p2],v1+v2); //尝试更新 
			}
		}
	} 
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=inf;
		for(int i=0;i<v[x].size();i++)
			for(int j=0;j<v[y].size();j++){
				int p1=v[x][i].fi,p2=v[y][j].fi;
				int v1=v[x][i].se,v2=v[y][j].se;
//				cout<<p1<<' '<<p2<<" "<<v1<<" "<<v2<<"\n"; 
				ans=min(ans,f[p1][p2]+v1+v2);
			} 
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}

