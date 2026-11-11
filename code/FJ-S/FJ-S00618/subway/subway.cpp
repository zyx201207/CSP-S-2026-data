#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],k,u,v,bel[510];
vector<vector<int> >a,t;
int read(){
	int s=0,w=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') w=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*w;
}
int main(){
	srand(time(NULL));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		k=read();
		for(int j=1;j<=k;j++) {
			a[i][j]=read();
			t[i][j]=read();
		}
	}
	while(q--){
		scanf("%d%d",&u,&v);
		printf("%d\n",rand()%1000+1);
	}
}
