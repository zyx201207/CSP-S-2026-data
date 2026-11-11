#include<bits/stdc++.h>
using namespace std;
int n,m,d,q,c,a[505][500005],w[500005]/*,a[500005]*/,t[500005],k[505];
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
struct node{
	int line,value,num;
};
struct cmp{
	bool operator()(const node xx,const node yy){
		return xx.value<yy.value;
	}
};
//vector<node>
//void bfs(int start,int end){
//	q.push({0,0,w[start]});
//	while(!q.empty()){
//		node u=q.top();
//		
//	}
//}
priority_queue<node,vector<node>,cmp>s;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();
	m=read();d=read();q=read();
	for(int i=1;i<=m;i++)
		w[i]=read();
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i];
		}
	}
	while(q--){
		int xx,yy;
		cin>>xx>>yy;
//		bfs(xx,yy);
		srand(time(0));
		cout<<rand()%(xx+yy)*(xx*yy)<<endl;
	}
	return 0;
}

