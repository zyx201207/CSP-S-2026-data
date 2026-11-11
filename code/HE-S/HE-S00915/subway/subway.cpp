#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,w[500005],k[505],a[500][500005],t[500][500005],x[100005],y[100005];

int read(){
	int f=1,k=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return f*k;
}
void out(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x<10)putchar(x+'0');
	else{
		out(x/10);
		putchar(x%10+'0');
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			a[i][j]=read();
		}
		for(int j=1;j<=k[i];j++){
			t[i][j]=read();
		}
	}
	for(int i=1;i<=q;i++){
		x[i]=read();
		y[i]=read();
		int ans=w[x[i]]+w[y[i]];
		
	}
	return 0;
}
