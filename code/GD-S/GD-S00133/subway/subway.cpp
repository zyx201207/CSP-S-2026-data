#include<bits/stdc++.h> 
using namespace std;

const int N=2e5+10;
int c,n,m,dd,q,x[N],le,k=1;
int pre[N*2],d[N*2],xx,y;
bool f[N*2];
struct Node {
	int to,next,len,non;
}a[N*4];
void add(int u,int v,int l) {
	a[k].to=v;
	a[k].len=l;
	a[k].next=pre[u];
	pre[u]=k;
	k++;
}
void dfs(int x) {
	for(int i=pre[x];i;i=a[i].next) {
		int to=a[i].to;
		
		
		if(d[to]>d[x]+a[to].len) {
			d[to]=a[to].len+d[x];
		//	cout<<x<<' '<<to<<' '<<a[to].len<<endl;
			dfs(to);
		}
	}
	return ;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++) {
		cin>>x[i];
		a[i].non=x[i];
	}
	for(int i=1;i<=n;i++) {
		int kk;
		cin>>kk;
		for(int j=1;j<=kk;j++) {
			cin>>x[j]>>le;
			add(x[j],x[j]+m,le);
			add(x[j]+m,x[j],le);
			if(j!=1) {
				add(x[j-1],x[j],0);
				add(x[j],x[j-1],0);	
			//	cout<<x[j-1]<<' '<<x[j]<<endl;	
			//	cout<<a[k-1].len<<endl;
			}
		}
	}
	for(int i=1;i<=q;i++) {
		cin>>xx>>y;
		memset(d,0x3f,sizeof(d));
		d[xx+m]=0;
		dfs(xx+m);
		cout<<d[y+m]+a[xx].non+a[y].non<<endl;
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
