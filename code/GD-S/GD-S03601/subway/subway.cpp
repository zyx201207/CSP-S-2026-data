#include<bits/stdc++.h>
using namespace std;
int n,m,C,q,d;
int w[500005];//c：i号站点所属线路 
int a[505][505];
int c[500005][25][2];
//就差一点……如果可以的话，vector就可以满分了 
struct xl{
	int a;
	int t;
};
xl v[505][500005];
xl k[50];
bool cmp(xl x,xl y){
	return x.a<y.a;
}
int tim(int x,int y){//两线最短换乘时间 
	int re=1e9,p=1;
	for(int i=1;i<=v[x][0].a;i++){
		while(v[y][p].a<v[x][i].a&&p<=v[y][0].a)
			p++;
		if(v[y][p].a==v[x][i].a){
			re=min(re,v[y][p].t+v[x][i].t);
		}
	}//预处理时间大概是1e5罢 
	return re;
}
//如果以线路为节点作图论的话，会简单不少
//预处理麻烦些，打算存储任意两个线路i,j换乘最小代价，然后做dij，最后加上起点终点就好了 
//可枚举两条线路，然后对比中转地铁站(站点编号需排序)，拿出最小就得到了，需要处理中转站 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int X;
		cin>>X;
		for(int j=1;j<=X;j++){
			cin>>k[j].a;
			cin>>k[j].t;
			c[k[j].a][0][0]++;
			c[k[j].a][c[k[j].a][0][0]][0]=i;
			c[k[j].a][c[k[j].a][0][0]][1]=k[j].t;
		}
		sort(k+1,k+1+X,cmp);
		v[i][0].a=X;
		for(int j=1;j<=X;j++){
			v[i][j].a=k[j].a;
			v[i][j].t=k[j].t;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=1e9;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				a[i][j]=a[j][i]=tim(i,j);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j&&j!=k&&i!=k)
					a[j][i]=a[i][j]=min(a[i][k]+a[k][j],a[i][j]);
			}
		}
	}
	for(int i=1;i<=n;i++)
		a[i][i]=0;
	for(int i=1;i<=q;i++){
		int s,e,ans=1e9;
		cin>>s>>e;
		for(int j=1;j<=c[s][0][0];j++){
			for(int k=1;k<=c[e][0][0];k++){
				ans=min(ans,a[c[s][j][0]][c[e][k][0]]+c[s][j][1]+c[e][k][1]+w[s]+w[e]);
			}
		}
		cout<<ans<<'\n';		
	}
	return 0;
}
