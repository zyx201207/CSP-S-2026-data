#include<bits/stdc++.h>
using namespace std;
long long read(){
	char c;
	long long a=0,f=1;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(!(c<'0'||c>'9')){
		a*=10,a+=c-'0';
		c=getchar();
	}
	return a*f;
}
void write(long long a){
	if(a<0){
		putchar('-');
		a*=-1;
	}
	if(a>=10)write(a/10);
	putchar(a%10+'0');
	return;
}
struct node{
	int id,s;
};
long long c,n,m,d,q,w[500005],k,a,b,cd[505][505];
vector<node> v[500005];
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k||cd[i][k]==0)continue;
			for(int j=1;j<=n;j++) {
				if(i==j||k==j||cd[j][k]==0)continue;
				if(cd[i][j]==0)cd[i][j]=cd[i][k]+cd[j][k];
				else cd[i][j]=min(cd[i][j],cd[i][k]+cd[j][k]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		k=read();
		for(int j=1;j<=k;j++){
			a=read(),b=read();
			for(int j=0;j<v[a].size();j++){
				if(cd[i][v[a][j].id]==0)cd[i][v[a][j].id]=cd[v[a][j].id][i]=b+v[a][j].s;
				else cd[i][v[a][j].id]=cd[v[a][j].id][i]=min(cd[i][v[a][j].id],(long long)(b+v[a][j].s));
			}
			v[a].push_back((node){i,b});
		}
	}
	floyd();
	while(q--){
		a=read(),b=read(),d=1e18;
		for(int i=0;i<v[a].size();i++){
			for(int j=0;j<v[b].size();j++){
				d=min(d,cd[v[a][i].id][v[b][j].id]+w[a]+w[b]+v[a][i].s+v[b][j].s);
			}
		}
		write(d);
		puts("");
	}
	return 0;
} 
