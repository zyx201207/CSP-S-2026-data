#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int MAXN=2e4+2;
int c,n,m,d,q;
int tout[MAXN];
int sub[502][MAXN];
int tim[MAXN][22];
int cnt[MAXN];
int book[MAXN];
long long check(int x,int y){
	if(x==y){
		return 0;
	}
	long long ans=1e9;
	book[x]=1;
	for(int i=1; i<=cnt[x]; i++){
		for(int j=1; j<=sub[i][0]; j++){
			if(book[j]==1){
				continue;
			}
			ans=min(ans,tim[x][i]+check(sub[i][j],y)+tim[j][i]);
		}
	}
	book[x]=0;
	return ans;
}
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1; i<=m; i++){
		tout[i]=read();
	}
	for(int i=1; i<=n; i++){
		sub[i][0]=read();
		for(int k=1; k<=sub[i][0]; k++){
			sub[i][k]=read();
			tim[sub[i][k]][i]=read();
			cnt[sub[i][k]]++;
		}
	}
	for(int i=1; i<=q; i++){
		int x=read();
		int y=read();
		cout<<check(x,y)+tout[x]+tout[y]<<endl;
	}
	
	return 0;
}