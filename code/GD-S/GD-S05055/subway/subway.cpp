#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,k,t1,t2;
struct sta{
	int w;
}a[500005]; 
struct way{
	int u,v,l;
}b[700];
long long sumt;
bool cmp(way p1,way p2){
	return p1.l<p2.l;
}
void dfs(int x,int y,long long sum,int lll){
	b[lll].u=0;
	b[lll].v=0;
	if(x==y){
		if(sum<=sumt){
			sumt=sum;
			return ;
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i].u==x){
			dfs(b[i].v,y,sum+b[i].l,i);
		}
		if(b[i].v==x){
			dfs(b[i].u,y,sum+b[i].l,i);
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
    	cin>>a[i].w;//输入从地铁口到站厅时间 
	}
	for(int i=1;i<=n;i++){
		cin>>k;//输入此路线经过站点数 
		cin>>b[i].u;
		cin>>t1;
		cin>>b[i].v;//存边 
		cin>>t2;
		b[i].l=t1+t2;
	}
	sort(b+1,b+n+1,cmp); 
    for(int i=1;i<=q;i++){
    	sumt=0;
    	cin>>x>>y;
    	sumt+=a[x].w;
    	sumt+=a[y].w;
    	dfs(x,y,sumt,0);
    	cout<<sumt;
	}
	return 0;
} 
