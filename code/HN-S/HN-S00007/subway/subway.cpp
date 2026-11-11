#include<bits/stdc++.h>//100
#define int long long
#define rag(i,l,r) for(i=(l);i<=(r);i++)
#define reg(i,r,l) for(i=(r);i>=(l);i--)
#define irag(i,l,r) for(int i=(l);i<=(r);i++)
#define ireg(i,r,l) for(int i=(r);i>=(l);i--)
using namespace std;
template<typename x>x maxx(x a){return a;}
template<typename x,typename y>x maxx(x a,y b){return a<b?b:a;}
template<typename x,typename y,typename...z>x maxx(x a,y b,z...c){return maxx(maxx(a,b),c...);}
template<typename x>x minn(x a){return a;}
template<typename x,typename y>x minn(x a,y b){return a<b?a:b;}
template<typename x,typename y,typename...z>x minn(x a,y b,z...c){return minn(minn(a,b),c...);}
const int TMXO_n=520,TMXO_m=5e5+100;
int c,n,m,d,p,i,j,k,w[TMXO_m],q,z,vv,Min;
struct node{int z,w;};
vector<node>lj[TMXO_m];
vector<node>sta[TMXO_m];

int dis[TMXO_n][TMXO_n];bool v[TMXO_n];
void dijkstra(int ID,int q){
	memset(v,false,sizeof(v));
	dis[ID][q]=0;
	int Mini=0;
	irag(i,1,n){
		Mini=0;
		irag(j,1,n)if(!v[j]&&dis[ID][j]<dis[ID][Mini])Mini=j;
		v[Mini]=true;
		for(node ed:lj[Mini])if(!v[ed.z]&&dis[ID][ed.z]>dis[ID][Mini]+ed.w)dis[ID][ed.z]=dis[ID][Mini]+ed.w;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>p;
	rag(i,1,m)cin>>w[i];
	rag(i,1,n){
		cin>>j;
		while(j--){
			cin>>z>>vv;
			sta[z].push_back((node){i,vv});
		}
	}
	rag(i,1,m){
		for(node a:sta[i])for(node b:sta[i])if(a.z!=b.z){
			lj[a.z].push_back((node){b.z,a.w+b.w});
			lj[b.z].push_back((node){a.z,a.w+b.w});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	rag(i,1,n)dijkstra(i,i);
	rag(i,1,p){
		cin>>q>>z;
		Min=LLONG_MAX;
		for(node a:sta[q])for(node b:sta[z]){
			Min=minn(Min,dis[a.z][b.z]+a.w+b.w);
		}
		cout<<Min+w[q]+w[z]<<endl;
	}
	return 0;
}
/*
in1:
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
out1:
32
17
in2:
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
out2:
35
16
*/
