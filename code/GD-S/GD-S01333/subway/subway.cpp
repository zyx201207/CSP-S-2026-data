#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int w[500001],k[501],ss[500001];
vector<int> t[501],a[501],id[500001],z[500001];
long long v[500001];
queue<int> q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,qq,x,y,xx,yy,u1,u2;
	scanf("%d%d%d%d%d",&c,&m,&n,&d,&qq);
	for(int i=1;i<=n;i++) scanf("%d",w+i);
	
	for(int i=1;i<=m;i++){
		scanf("%d",k+i);
		
		for(int j=0;j<k[i];j++){
			scanf("%d%d",&x,&y);
			a[i].push_back(x);
			t[i].push_back(y);
			id[x].push_back(i);
			z[x].push_back(j);
			ss[x]++;
		}  
	}
	while(qq--){
		scanf("%d%d",&u1,&u2);
		memset(v,0x3f,sizeof v);
		q.push(u1);
		v[u1]=1;
		
		while(!q.empty()){
			x=q.front();
			q.pop();
			for(int i=0;i<ss[x];i++){
				xx=id[x][i];
				yy=z[x][i];
				for(int j=yy+1;j<k[xx];j++){
					if(v[a[xx][j]]>v[x]+t[xx][yy]+t[xx][j]){
						q.push(a[xx][j]);
						v[a[xx][j]]=v[x]+t[xx][yy]+t[xx][j];
						cout<<a[xx][j]<<' ';
					}
				}
				
			}
		}
		printf("%lld\n",w[u1]+w[u2]+v[u2]-1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
