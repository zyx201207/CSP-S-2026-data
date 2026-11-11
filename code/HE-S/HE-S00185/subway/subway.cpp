#include<bits/stdc++.h>
using namespace std;
const long long inf=0x3f3f3f3f3f3f3f3f;
long long c,c1,n,m,d,p,a[500010],ai,ti,l[2010][2010],len1,len2,ans;
struct node{
	long long v,w;
};
vector<node>t[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&p);
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			l[j][i]=l[i][j]=inf;
		}
	}
	for(long long i=1;i<=m;i++){scanf("%lld",a+i);}
	for(long long u=1,v,w;u<=n;u++){
		scanf("%lld",&c);
		for(long long i=1;i<=c;i++){
			scanf("%lld %lld",&v,&w);
			t[v].push_back({u,w});
		}
	}
	for(long long i=1;i<=m;i++){
		c=t[i].size();
		for(long long u=0;u<c;u++){for(long long v=u+1;v<c;v++){
			l[t[i][u].v][t[i][v].v]=t[i][u].w+t[i][v].w;
			l[t[i][v].v][t[i][u].v]=t[i][v].w+t[i][u].w;
		}}
	}
	//jt5e5*400
	for(long long l1=1;l1<=n;l1++){
		for(long long u=1;u<=n;u++){
			if(l1==u)continue;
			for(long long v=1;v<=n;v++){
				if(u==v||l1==v)continue;
				l[u][v]=min(l[u][v],l[u][l1]+l[l1][v]);
			}
		}
	}
	long long x,y;
	for(long long i=1;i<=p;i++){
		ans=inf;
		scanf("%lld %lld",&x,&y);
		len1=t[x].size();
		len2=t[y].size();
		for(long long u=0;u<len1;u++){
			for(long long v=0;v<len2;v++){
				ans=min(ans,l[t[x][u].v][t[y][v].v]+t[x][u].w+t[y][v].w);
			}
		}
		printf("%lld\n",ans+a[x]+a[y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/ 
