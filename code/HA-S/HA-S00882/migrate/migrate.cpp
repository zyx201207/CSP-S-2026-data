#include<bits/stdc++.h>
using namespace std;
int read_i(){
	char re;
	int r=1;
	re=getchar();
	while(re>'9'||re<'0'){
		if(re=='-')r=-1;
		re=getchar();
	}
	int x=0;
	while(re>='0'&&re<='9'){
		x*=10;
		x+=re-'0';
		re=getchar();
	}
	return x*r;
}
int c,n,m,d,qp;
int a[200001];
int b[200001];
int T;
void dfs(int i,int po){
	if(i==m&&po==b[m]){
		qp++;
		return;
	}
	for(int y=i+1;a[i]+m>=a[y];y++){
		dfs(y,i+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read_i();
	T=read_i();
	while(T--){
		n=read_i();
		m=read_i();
		for(int i=1;i<=n;i++){
			a[i]=read_i();
		}
		memset(b,0x3f3f3f,sizeof(b));
		queue<int>q;
		queue<int>q2;
		queue<int>q3;
		q.push(a[1]);
		q2.push(0);
		q3.push(1);
		while(!q.empty()){
			int t=q.front();
			int z=q2.front();
			int zc=q3.front();
			if(zc==n){
				break;
			}
			q.pop();
			q2.pop();
			q3.pop();
			for(int y=zc+1;a[zc]+m>=a[y];y++){
				if(b[zc]+1>b[y])continue;
				b[y]=b[zc]+1;
				q.push(a[y]);
				q2.push(b[y]);
				q3.push(y);
			}
		}
		dfs(1,0);
		cout<<qp-1<<"\n";
	}
	return 0;
}
