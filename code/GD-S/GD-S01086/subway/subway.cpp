#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3fll;
const int N=5010;
ll c,m,d,q,n,num;
ll dis[N][N];
struct node{
	ll u,t,id;
}a[N];
void floyed(){
	for(int k=1;k<=num;k++){
		for(int i=1;i<=num;i++){
			if(i==k||dis[i][k]==inf){
				continue;
			}
			for(int j=1;j<=num;j++){
				if(j==i||j==k){
					continue;
				}
				if(dis[k][j]==inf){
					continue;
				} 
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof(dis));
	for(int i=0;i<=N-10;i++){
		dis[i][i]=0;
	}
	//µØÌú¿Ú£º1~m
	//Õ¾Ìü£ºm+1~2*m 
	for(int i=1;i<=m;i++){
		ll w;
		cin>>w;
		dis[i][i+m]=dis[i+m][i]=w;
	} 
	num=2*m;
	for(int i=1;i<=n;i++){
		ll len;
		cin>>len;
		for(int j=1;j<=len;j++){
			cin>>a[j].u>>a[j].t;
			num++;
			a[j].id=num;
			dis[a[j].u+m][num]=dis[num][a[j].u+m]=a[j].t;
		}
		for(int uu=1;uu<=len;uu++){
			for(int vv=1;vv<=len;vv++){
				ll xx=a[uu].id,yy=a[vv].id;
				dis[xx][yy]=dis[yy][xx]=0;
			}
		}
	} 
	floyed();
	while(q--){
		ll u,v;
		cin>>u>>v;
		cout<<min(dis[v][u],dis[u][v])<<"\n";
	} 
	return 0;
} 
