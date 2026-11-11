#include<bits/stdc++.h>
using namespace std;
long long c,n,m,s,g,q,x,y,z,ans,a[1000005],e[1005][1005];
vector<pair<long long,long long> >d[1000005];
long long read(){
	long long ans=0;
	char c=0;
	bool f=0;
	while(c<'0'||c>'9')c=getchar(),f|=(c=='-');
	while(c>='0'&&c<='9')ans=ans*10+c-'0',c=getchar();
	return f?-ans:ans;
}
void write(long long x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),g=read(),q=read(),memset(e,0x3f,sizeof(e));
	for(int i=1;i<=m;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		s=read(),e[i][i]=0;
		for(int j=1;j<=s;j++)x=read(),y=read(),d[x].push_back(make_pair(i,y));
	}
	for(int i=1;i<=m;i++){
		s=d[i].size();
		for(int j=0;j<s;j++)
		    for(int k=0;k<j;k++)
		        x=d[i][j].first,y=d[i][k].first,z=d[i][j].second+d[i][k].second,e[x][y]=min(e[x][y],z),e[y][x]=min(e[y][x],z);
	}
	for(int k=1;k<=n;k++)
	    for(int i=1;i<=n;i++)
	        for(int j=1;j<=n;j++)
	            e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
	while(q--){
		x=read(),y=read(),ans=1e18;
		for(int i=0;i<d[x].size();i++)
		    for(int j=0;j<d[y].size();j++)
		        ans=min(ans,d[x][i].second+d[y][j].second+e[d[x][i].first][d[y][j].first]);
		write(ans+a[x]+a[y]),putchar('\n');
	}
	return 0;
}

