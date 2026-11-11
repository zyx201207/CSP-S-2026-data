#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
struct ed{
	int v;
	ll w;
	ed(int V=0,ll W=0):v(V),w(W){}
};
vector<ed>e[N];
ll ww[N],dis[520][520];
inline ll min(ll a,ll b){
	if(a<b)return a;
	else return b;
}
inline void read(ll&x){
	x=0;
	ll num=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		num=num*10+1ll*(c-'0');
		c=getchar();
	}
	x=num;
}
inline void read(int&x){
	x=0;
	ll num=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		num=num*10+1ll*(c-'0');
		c=getchar();
	}
	x=num;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)read(ww[i]);
    for(int j=1;j<=n;j++){
    	int tt;
    	scanf("%d",&tt);
    	while(tt--){
    		int v;
    		ll cc;
    	    read(v);
    		read(cc);
    		e[v].push_back(ed(j,cc));
		}
	}
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++){
	    	if(i!=j)dis[i][j]=1e18;
	    	else dis[i][j]=0;
		}
	for(int i=1;i<=m;i++){
		int sz=e[i].size();
		for(int j=0;j<sz-1;j++){
			for(int k=j+1;k<sz;k++){
				ed t1=e[i][j],t2=e[i][k];
				int v1=t1.v,v2=t2.v;
				dis[v1][v2]=min(dis[v1][v2],t1.w+t2.w);
			}
		}
	}
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++){
	  	if(dis[i][j]<1e18)dis[j][i]=dis[i][j];
		}
	for(int j=1;j<=n;j++)
	    for(int i=1;i<=n;i++)
	        for(int k=1;k<=n;k++)
	            dis[i][k]=min(dis[i][k],dis[i][j]+dis[j][k]);
	while(q--){
		int x,y;
		read(x),read(y);
		ll num=1e18;
	    for(ed t1:e[x])
			for(ed t2:e[y])
	    		num=min(num,dis[t1.v][t2.v]+t1.w+t2.w);
		printf("%lld\n",num+ww[x]+ww[y]);
	}
return 0;
}
