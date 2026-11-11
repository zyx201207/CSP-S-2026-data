#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T &x){
	x=0;bool bj=0;char s=getchar();
	while(s<'0'||s>'9'){
		if(s=='-')bj=1;
		s=getchar();
	}
	while(s>='0'&&s<='9'){
		x=x*10+(s^48);
		s=getchar();
	}
	if(bj)x=-x;
}
template<typename T>void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
long long c,n,m,d,q,w[500666],sj[500666];
vector<pair<int,int>> dt[500666];
queue<int> p;
long long bfs(int x,int y){
	p.push(x);
	memset(sj,0,sizeof(sj));
	while(!p.empty()){
		int ls=p.front();p.pop();
		if(ls==y)continue;
		for(int i=0;i<(int)dt[ls].size();i++){
			int ls1=dt[ls][i].first,ls2=dt[ls][i].second;
			if(sj[ls1]==0||sj[ls]+ls2<sj[ls1]){
				sj[ls1]=sj[ls]+ls2;
				p.push(ls1);
			}
		}
	}
	return sj[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c),read(n),read(m),read(d),read(q);
	for(int i=1;i<=m;i++)read(w[i]);
	for(int i=1,k;i<=n;i++){
		read(k);
		for(int j=1,a,t;j<=k;j++){
			read(a),read(t);
			dt[a].push_back({m+i,t});
			dt[m+i].push_back({a,t});
		}
	}
	while(q--){
		int x,y;read(x),read(y);
		write(bfs(x,y)+w[x]+w[y]);
		cout<<"\n";
	}
	return 0;
}
