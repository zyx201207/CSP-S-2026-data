#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
vector<int>a[500005],b[505],e[505];
//a：站所在线路 b：线路中站 c：线路中站距离 
long long md[500005]; bool used[500005];
void work1(int x,int y){
	for(int i=1; i<=m; i++){
		md[i]=4e18; used[i]=1;
	}
	md[x]=(long long)(w[x]+w[y]);
	for(int o=1; o<=m; o++){
		int id=-1; long long dis=5e18;
		for(int i=1; i<=m; i++)
			if(used[i]&&md[i]<dis){
				dis=md[i]; id=i;
			}
		if(id==y){
			printf("%lld\n",md[y]);
			return ;
		}
		if(id==-1){
			printf("-1\n");
			return ;
		}
		used[id]=0;
		for(int i:a[id]){
			int id2=-1;
			for(int j=0; j<b[i].size(); j++)
				if(b[i][j]==id){
					id2=j; break;
				}
			for(int j=0; j<b[i].size(); j++)
				if(used[b[i][j]])
					md[b[i][j]]=min(md[b[i][j]],md[id]+(long long)(e[i][j]+e[i][id2]));
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1; i<=m; i++)
		scanf("%d",&w[i]);
	for(int i=1; i<=n; i++){
		int len; scanf("%d",&len);
		while(len--){
			int x,y;
			scanf("%d%d",&x,&y);
			a[x].push_back(i);
			b[i].push_back(x);
			e[i].push_back(y);
		}
	}
	if(1<=c&&c<=8)//ok
		while(q--){
			int x,y;
			scanf("%d%d",&x,&y);
			work1(x,y);
		}
	return 0;
}

