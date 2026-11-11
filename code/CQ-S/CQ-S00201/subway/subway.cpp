#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[510],a[510][20010],x,y;
long long int sum,t[510][20010],w[20010];
vector<vector<int>> z,z1;//z[地铁站序号][地铁线路]=这个线路的第几个站，z1[地铁站序号][0~z1[地铁站序号.size()-1]=线路 
bool b[20010];
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!(ch>='0' and ch<='9')){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' and ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
long long int read1(){
	long long int x=0,f=1;
	char ch=getchar();
	while(!(ch>='0' and ch<='9')){
		if(ch=='-') f=-1;
		ch=getchar(); 
	}
	while(ch>='0' and ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
void dfs(int x,int y,int xl,long long int tim){
//	cout<<x<<' '<<y<<' '<<xl<<' '<<tim<<'\n'; 
	if(x==y){
		sum=min(sum,t[xl][z[y][xl]]+tim);
		return;
	}
	else{
		for(int i=0;i<z1[x].size();i++){
			if(xl!=z1[x][i]){
				if(z[x][z1[x][i]]==1){
					if(b[a[z1[x][i]][z[x][z1[x][i]]+1]]!=1){
						b[a[z1[x][i]][z[x][z1[x][i]]+1]]=1;
						dfs(a[z1[x][i]][z[x][z1[x][i]]+1],y,z1[x][i],tim+t[xl][z[x][xl]]+t[z1[x][i]][z[x][z1[x][i]]]);
						b[a[z1[x][i]][z[x][z1[x][i]]+1]]=0;
					}
				}
				else if(z[x][z1[x][i]]==k[z1[x][i]]){
					if(b[a[z1[x][i]][z[x][z1[x][i]-1]]]!=1){
						b[a[z1[x][i]][z[x][z1[x][i]-1]]]=1;
						dfs(a[z1[x][i]][z[x][z1[x][i]-1]],y,z1[x][i],tim+t[xl][z[x][xl]]+t[z1[x][i]][z[x][z1[x][i]]]);
						b[a[z1[x][i]][z[x][z1[x][i]-1]]]=0;
					}
				}
				else{
					if(b[a[z1[x][i]][z[x][z1[x][i]]+1]]!=1){
						b[a[z1[x][i]][z[x][z1[x][i]]+1]]=1;
						dfs(a[z1[x][i]][z[x][z1[x][i]]+1],y,z1[x][i],tim+t[xl][z[x][xl]]+t[z1[x][i]][z[x][z1[x][i]]]);
						b[a[z1[x][i]][z[x][z1[x][i]]+1]]=0;
					}
					if(b[a[z1[x][i]][z[x][z1[x][i]-1]]]!=1){
						b[a[z1[x][i]][z[x][z1[x][i]-1]]]=1;
						dfs(a[z1[x][i]][z[x][z1[x][i]-1]],y,z1[x][i],tim+t[xl][z[x][xl]]+t[z1[x][i]][z[x][z1[x][i]]]);
						b[a[z1[x][i]][z[x][z1[x][i]-1]]]=0;
					}
				}
			}
			else{
				if(z[x][z1[x][i]]==1){
					if(b[a[z1[x][i]][z[x][z1[x][i]]+1]]!=1){
						b[a[z1[x][i]][z[x][z1[x][i]]+1]]=1;
						dfs(a[z1[x][i]][z[x][z1[x][i]]+1],y,z1[x][i],tim);
						b[a[z1[x][i]][z[x][z1[x][i]]+1]]=0;
					}
				}
				else if(z[x][z1[x][i]]==k[z1[x][i]]){
					if(b[a[z1[x][i]][z[x][z1[x][i]-1]]]!=1){
						b[a[z1[x][i]][z[x][z1[x][i]-1]]]=1;
						dfs(a[z1[x][i]][z[x][z1[x][i]-1]],y,z1[x][i],tim);
						b[a[z1[x][i]][z[x][z1[x][i]-1]]]=0;
					}
				}
				else{
					if(b[a[z1[x][i]][z[x][z1[x][i]]+1]]!=1){
						b[a[z1[x][i]][z[x][z1[x][i]]+1]]=1;
						dfs(a[z1[x][i]][z[x][z1[x][i]]+1],y,z1[x][i],tim);
						b[a[z1[x][i]][z[x][z1[x][i]]+1]]=0;
					}
					if(b[a[z1[x][i]][z[x][z1[x][i]-1]]]!=1){
						b[a[z1[x][i]][z[x][z1[x][i]-1]]]=1;
						dfs(a[z1[x][i]][z[x][z1[x][i]-1]],y,z1[x][i],tim);
						b[a[z1[x][i]][z[x][z1[x][i]-1]]]=0;
					}
				}
			}
		}
	} 
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	z.resize(m+2);
	z1.resize(m+2);
	for(int i=1;i<=m;i++){
		z[i].resize(510);
		w[i]=read1();
	}
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			a[i][j]=read(),t[i][j]=read1();
			z1[a[i][j]].emplace_back(i);
			z[a[i][j]][i]=j;
		}
	}
	for(int i=1;i<=q;i++){
		x=read(),y=read();
		sum=LLONG_MAX;
		for(int j=0;j<z1[x].size();j++){
			dfs(x,y,z1[x][j],w[x]+w[y]+t[z1[x][j]][z[x][z1[x][j]]]);
		}
		cout<<sum<<'\n';
	}
	return 0;
}
