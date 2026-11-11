#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500524],k[500524];
struct node{
	long long a,t;
};
long long x,y,ans,len=0,pre[10024];
vector <node> vec[500524];
long long id_xl(long long z){
	return z+m;
}
struct node1{
	long long u,num;
};
struct node2{
	long long u,v,w;
};
node2 r[500024];
bool f[500024];
void bfs(long long s,long long e){
	ans=1e10+8;
	for(int j = 1;j <= m+n+8;j++){
		f[j]=0;
	}
	queue <node1> q;
	q.push({s,0});
	f[s]=1;
	while(!q.empty()){
		auto [u,num]=q.front();
		q.pop();
		for(auto [a,t]:vec[u]){
			if(a==e){
				if(ans>num+t){
					ans=num+t;
					pre[a]=u;
				}
			}else if(!f[a]){
				f[a]=1;
				pre[a]=u;
				q.push({a,num+t});
			}
		}
	}
	cout << ans+w[s]+w[e] << '\n';
}
bool cmp(node2 z1,node2 z2){
	return z1.w<z2.w;
}
long long fa[500024];
long long find(long long z){
	if(fa[z]==z)return z;
	return fa[z]=find(fa[z]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= m+n+8;i++){
		fa[i]=i;
	}
	long long a_,t_;
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			cin >> a_ >> t_;
			r[++len].u=id_xl(i);
			r[len].v=a_;
			r[len].w=t_;
		}
	}
	sort(r+1,r+n+1,cmp);
	long long r1,r2;
	for(int i = 1;i <= len;i++){
		r1=find(r[i].u),r2=find(r[i].v);
		if(r1!=r2){
			fa[r2]=r1;
			vec[r[i].u].push_back({r[i].v,r[i].w});
			vec[r[i].v].push_back({r[i].u,r[i].w});
		}
	}
	for(int i = 1;i <= q;i++){
		cin >> x >> y;
		bfs(x,y);
	}
	return 0;
}
