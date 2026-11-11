#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a[500005],k[500005],l,x,y;
struct node{
	long long id,x;
};
node zt[500005][25];
long long hc[505][505];
inline int read(){
	long long x=0,f=1;
	char c;
	c=getchar();
	while(!(c>='0' and c<='9')){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0' and c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
void write(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>0){
		write(x/10);
		putchar(x%10+'0');
	}
	return;
}
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	write(1);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
//	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		l=read();
		for(int j=1;j<=l;j++){
			x=read();
			y=read();
			zt[x][++k[x]]={i,y};
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				hc[i][j]=1E18;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=k[i];j++){
			for(int kk=1;kk<=k[i];kk++){
				if(zt[i][j].id!=zt[i][kk].id){
					hc[zt[i][j].id][zt[i][kk].id]=min(hc[zt[i][j].id][zt[i][kk].id],zt[i][j].x+zt[i][kk].x);
					hc[zt[i][kk].id][zt[i][j].id]=hc[zt[i][j].id][zt[i][kk].id];
				}
			}
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				for(int kk=1;kk<=n;kk++){
					if(kk!=j and kk!=i){
						hc[i][j]=min(hc[i][kk]+hc[kk][j],hc[i][j]);
					}
				}
			}
		}
	}
//	cin>>q;
	for(int i=1;i<=q;i++){
		x=read();
		y=read();
		long long ans=1E18;
		for(int j=1;j<=k[x];j++){
			for(int kk=1;kk<=k[y];kk++){
				if(zt[x][j].id==zt[y][kk].id){
					ans=min(ans,zt[x][j].x+zt[y][kk].x);
				}else{
					ans=min(ans,hc[zt[x][j].id][zt[y][kk].id]+zt[x][j].x+zt[y][kk].x);
				}
			}
		}
		write(ans+a[x]+a[y]);
		putchar('\n');
	}
	return 0;
}
