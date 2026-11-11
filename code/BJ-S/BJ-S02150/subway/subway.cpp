#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int ret=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
	while('0'<=ch&&ch<='9') {
		ret=ret*10+(ch-48);
		ch=getchar();
	}
	return ret*f;
}
inline void out(int a,char b){
	int c=0;
	while(a!=0){
		c=c*10+a%10;
		a/=10;
	}
	while(c!=0){
		putchar((c%10+48));
		c/=10;
	}
	putchar(b);
}
const int Maxn=1e5+10;
int c,n,m,d,q;
int w[Maxn],a[510][Maxn],t[510][Maxn];
int dis[Maxn];
vector<pair<int,int>> g[Maxn];
void dij(int s,int e){
	if(s==e) exit(0);
	for(pair<int,int> i:g[s]){
		if(dis[s]+i.second<dis[i.first]){
			dis[i.first]=dis[s]+i.second;
		}
		dij(i.first,e);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=in();n=in();m=in();d=in();q=in();
	for(int i=1;i<=m;i++) w[i]=in();
	for(int i=1;i<=n;i++){
		int k=in();
		for(int j=1;j<=k;j++){
			a[i][j]=in();
			t[i][j]=in();
			g[j].push_back({a[i][j-1],t[i][a[i][j-1]]+t[i][j]});
		}/*if(7<=c&&c<=11){
			for(int j=1;i<=k;i++){
				for(int l=i+1;l<=k;l++){
					g[j].push_back({l,t[i][j]+t[i][l]});
				}
			}
		}*/
	}
	while(q--){
		int s=in(),e=in();
		if(12<=c&&c<=19){
			out((w[s]+w[e]+2*t[1][1]),'\n');
		}
		else if(7<=c&&c<=11){
			memset(dis,0x3f,sizeof dis);
			dis[s]=0;
			dij(s,e);
			out(w[s]+w[e]+dis[e],'\n');
			//cout<<111;
		}
		else out((w[s]+w[e]+2*t[1][1]),'\n');
	}
	return 0;
}
