#include "bits/stdc++.h"
using namespace std;
#define int long long
int c,n,m,d,q;
int val[500005],dis[505][505];
vector<pair<int,int> > lines[500005];
void read(int &x){
	x=0;
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
}
void write(int x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
signed main(void){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c),read(n),read(m),read(d),read(q);
	for(int i=1;i<=m;i++) read(val[i]);
	for(int i=1,len;i<=n;i++){
		read(len);
		for(int j=1,a,t;j<=len;j++) read(a),read(t),lines[a].push_back({i,t});
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) dis[i][j]=1e18;
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++)
		for(int jj=0;jj<(int)lines[i].size();jj++)
			for(int kk=jj+1;kk<(int)lines[i].size();kk++){
				int j=lines[i][jj].first,k=lines[i][kk].first,t1=lines[i][jj].second,t2=lines[i][kk].second;
				if(dis[j][k]>t1+t2) dis[j][k]=dis[k][j]=t1+t2; 
			}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(dis[i][j]>dis[i][k]+dis[k][j])
					dis[i][j]=dis[i][k]+dis[k][j];
	while(q--){
		int S,T;
		read(S),read(T);
		int ans=1e18;
		for(pair<int,int> i:lines[S])
			for(pair<int,int> j:lines[T])
				ans=min(ans,dis[i.first][j.first]+i.second+j.second+val[S]+val[T]);
		write(ans),putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
}
