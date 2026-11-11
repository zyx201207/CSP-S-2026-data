#include<bits/stdc++.h>
using namespace std;
const int MAXN=505,MAXM=500005;
int c,n,m,d,q;
long long w[MAXM],Graph[MAXN][MAXN],len[MAXM];
struct L{
	int id;
	long long len;
}st[MAXM][25];
vector<L>l[MAXN];
int k[MAXN],a[MAXN][MAXM],num[MAXM];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);//cin>>w[i];
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);//cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int id;long long len;
			scanf("%d%lld",&id,&len);
			//cin>>id>>len;
			st[id][++num[id]]={i,len};
			l[i].push_back({id,len});
		}
	}
	memset(Graph,0x3f,sizeof(Graph));
	for(int i=1;i<=n-1;i++){
		for(int j=0;j<k[i];j++)len[l[i][j].id]=l[i][j].len;
		for(int j=i+1;j<=n;j++){
			long long tmp=LLONG_MAX;
			for(int t=0;t<k[j];t++){
				L now=l[j][t];
				if(len[now.id])tmp=min(tmp,len[now.id]+now.len);
			}
			if(tmp!=LLONG_MAX)Graph[i][j]=Graph[j][i]=tmp;
		}
		for(int j=0;j<k[i];j++)len[l[i][j].id]=0;
	}//nk
	for(int i=1;i<=n;i++)Graph[i][i]=0;
	/*for(int i=1;i<=n;i++){
		for(int u=1;u<=n;u++)cout<<Graph[i][u]<<" ";
		cout<<endl;
	}*/
	for(int i=1;i<=n;i++){
		for(int u=1;u<=n;u++){
			for(int v=1;v<=n;v++){
				Graph[u][v]=min(Graph[u][v],Graph[u][i]+Graph[i][v]);
			}
		}
	}//n3
	/*for(int i=1;i<=n;i++){
		for(int u=1;u<=n;u++)cout<<Graph[i][u]<<" ";
		cout<<endl;
	}*/
	for(int i=1;i<=q;i++){
		long long ans=LLONG_MAX;
		int u,v;
		scanf("%d%d",&u,&v);
		//cin>>u>>v;
		for(int j=1;j<=num[u];j++){
			for(int jj=1;jj<=num[v];jj++){
				L l1=st[u][j],l2=st[v][jj];
				long long tmp=Graph[l1.id][l2.id]+l1.len+l2.len;
				ans=min(ans,tmp);
			}
		}
		printf("%lld\n",ans+w[u]+w[v]);
	}//d2q
	return 0;
}
//n^3+nk+d^2q
