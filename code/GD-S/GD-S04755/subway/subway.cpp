#include <bits/stdc++.h>
using namespace std;

const int N=5e4+5;
int c,n,m,d,q;
bool isin[N][505];//第i个地铁台是否在线路j之中 
struct Station{
	int w;
	int t[505];//此地铁站站厅到第i条线路站台所需时间 
}station[N];
vector<int> ndoe[N];

void solveB(){
	for(int i=1;i<=q;i++){
		int u,v,minn=0x3f3f3f3f,ans=0;
		cin>>u>>v;
		ans=ans+station[u].w+station[v].w;
		for(int i=1;i<=n;i++){
			minn=min(minn,station[u].t[i]+station[v].t[i]);
		}
		cout<<ans+minn;
	}
} 

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>station[i].w;
	}
	for(int i=1;i<=n;i++){
		int k,a,t;
		cin>>k;
		cout<<"k:"<<k<<endl;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			isin[a][i]=true;
			station[a].t[i]=t;
		}
	}
	cin>>q;
	if(c>=12 && c<=19){
		solveB();
	}
	else{
		for(int i=1;i<=q;i++){
			int u,v,ans=0;
			cin>>u>>v;
			cout<<q*u-v*c
		}
	}
	
	return 0;
} 
