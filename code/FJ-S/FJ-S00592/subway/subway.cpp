#include<iostream>
#include<vector>
#define gc getchar_unlocked
//#define gc _getchar_nolock
using namespace std;
typedef long long ll;
const int MAXN=507,MAXM=500007;
const ll INF=0x3f3f3f3f3f3f3f3f;
int read(){
	int res=0,flag=1,ch=gc();
	for(;!isdigit(ch);ch=gc())if(ch=='-')flag=-1;
	for(;isdigit(ch);ch=gc())res=res*10+(ch-'0');
	return res*flag;
}

int c,n,m,d,q;
struct trans{
	int tar;
	int len;
};
struct station{
	vector<trans> sub;
	int w;
}sta[MAXM];

ll dis[MAXN][MAXN];

void build(){
	for(int u=0;u<n;++u){
		for(int v=0;v<n;++v){
			dis[u][v]=(u==v)?0:INF;
		}
	}
	for(int i=0;i<m;++i){
		for(trans u:sta[i].sub){
			for(trans v:sta[i].sub){
				dis[u.tar][v.tar]=min(dis[u.tar][v.tar],ll(u.len+v.len));
			}
		}
	}
}

void floyd(){
	for(int k=0;k<n;++k){
		for(int u=0;u<n;++u){
			for(int v=0;v<n;++v){
				dis[u][v]=min(dis[u][v],dis[u][k]+dis[k][v]);
			}
		}
	}
}

ll query(int _u,int _v){
	ll tmp=INF;
	for(trans u:sta[_u].sub){
		for(trans v:sta[_v].sub){
			tmp=min(tmp,dis[u.tar][v.tar]+u.len+v.len);
		}
	}
	return tmp+sta[_u].w+sta[_v].w;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cout.tie(0);
	
	c=read();n=read();m=read();d=read();q=read();
	for(int i=0;i<m;i++)sta[i].w=read();
	for(int i=0,k,a,t;i<n;++i){
		k=read();
		for(int j=0;j<k;++j){
			a=read()-1;t=read();
			sta[a].sub.push_back({i,t});
		}
	}
	
	build();
	floyd();
	
	for(int i=0,u,v;i<q;++i){
		u=read()-1;v=read()-1;
		cout<<query(u,v)<<endl;
	}
	
	return 0;
}

