#include<bits/stdc++.h>
using namespace std;
int c,T,n,k,dis[105][105];
vector<int>e[1000005];
int read(){
	int x=0,y=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*y;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),T=read();
	if(c==13||c==14){
		while(T--){
			n=read(),k=read();
			int m=n/2;
			for(int i=1;i<=n;i++)
				e[i].clear();
			for(int i=1;i<n;i++){
				int u=read(),v=read();
				e[u].push_back(v),e[v].push_back(u);
			}
			if(k>=n){
				puts("0");
				continue;
			}
			if(k>=m){
				puts("1");
				continue;
			}
			int ans=max(((m+1)/2-(k+1)/2+1)/2,(m/2-k/2+1)/2);
			printf("%d\n",ans+1);
		}
	}
	while(T--){
		n=read(),k=read();
		memset(dis,0x3f,sizeof(dis));
		for(int i=1;i<=n;i++)
			e[i].clear(),dis[i][i]=0;;
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			e[u].push_back(v),e[v].push_back(u);
			dis[u][v]=1;
		}
		for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			if(i!=k)
				for(int j=i+1;j<=n;j++)
					if(j!=k)
						dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
		
		if(k>=n){
		puts("0");
			continue;
		}
		if(k>=n/2){
			puts("1");
			continue;
		}
		bool f=0;
		for(int i=1;i<=n;i++){
			f=0;
			for(int j=1;j<=n;j++)
				if(j!=i&&dis[i][j]!=1){
					f=1;
					break;
				}
			if(f==0)break;
		}
		if(f==0)puts("1");
		else puts("2");
	}
	return 0;
}
