#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=5e5+10;
const int maxnn=1e5+10;
LL c,n,m,d,q;
LL w[maxn];
int b[maxnn];
int e[maxnn];//起终点
bool walk[maxn];//是否走过 
int mymap[1500][1500][2];
int r[10005];
struct node{
	LL id,h;//h花费 
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
//	vector< vector<pair<LL,LL> >  > mymap(m+n);//m为车站，m+i为i号厅 
	
	for(int i=1;i<=m;i++){//地铁口到站厅 
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){//i号线 
		LL k;
		cin>>k;
		for(int j=1;j<=k;j++){
			LL idd,t;
			cin>>idd>>t;
			mymap[m+i][j][0]=idd;
			mymap[m+i][j][1]=t;
			r[m+i]++;
			mymap[idd][j][0]=m+i;
			mymap[idd][j][1]=t;
			r[idd]++;
		} 
	}
	for(int i=1;i<=q;i++){
		cin>>b[i]>>e[i];
	}
	for(int i=1;i<=q;i++){
		memset(walk,false,sizeof(walk));
		int sd=b[i];
		int ed=e[i];
		LL add=w[sd]+w[ed];
		LL ans=112644344117;
		queue<node> qu;
		node stp;
		stp.id=sd;
		stp.h=0;
		qu.push(stp);//起点入队
		walk[sd]=1;
		while(!qu.empty()){
			node np=qu.front();
			qu.pop();
			LL nowp=np.id;//目前所在点 
			if(nowp==ed){
				//到达终点 
				ans=min(ans,np.h+add);
				walk[ed]==0;
				continue;
			}
			int ii=1;
			while(ii<=r[nowp]){
				LL nc=mymap[nowp][ii][0];//可到达的点 
				if(walk[nc]==0){
					node wg;
					wg.id=nc;
					wg.h=np.h+mymap[nowp][ii][1];//叠加花费 
					qu.push(wg);
					walk[nc]=1;
				}
				ii++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
