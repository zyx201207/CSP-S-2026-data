#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=1100000;
int c,t,n,k,x,s[N],h[N];
bool flag;
vector<int>e[N];
void dfs1(int u,int fa){
	s[u]=0,h[u]=0;
	for(int v:e[u]){
		if(v==fa)continue;
		dfs1(v,u);
		s[u]+=s[v];
		h[u]=max(h[u],h[v]+1);
	}
	s[u]+=h[u]>=x;
}
void dfs2(int u,int fa,int u1,int d,int mxd){
	//cout<<u<<' '<<d<<' '<<mxd<<endl;
	if(d>mxd)return ;
	if(max(s[u],1)+max(s[u1],1)<=k){
		//cout<<u<<' '<<u1<<'!'<<endl;
		flag=1;return ;
	}
	int m1=0,m2=0;
	for(int v:e[u]){
		if(v==u1||v==fa)continue;
		if(h[v]>h[m1])m2=m1,m1=v;
		else if(h[v]>h[m2])m2=v;
	}
	//cout<<u<<":"<<m1<<' '<<m2<<endl;
	if(!m1)return ;
	if(!m2){dfs2(m1,u,u1,d+1,mxd);return ;}
	//cout<<u<<"->"<<m1<<':'<<min(mxd,d+x-h[m2]-1)<<endl;
	if(d+h[m2]+1>x)dfs2(m1,u,u1,d+1,min(mxd,d+x-h[m2]-1));
	else dfs2(m1,u,u1,d+1,mxd);
	if(flag)return ;
	for(int v:e[u]){
		if(v==u1||v==fa||v==m1)continue;
		if(d+h[m1]+1>x)dfs2(v,u,u1,d+1,min(mxd,d+x-h[m1]-1));
		else dfs2(v,u,u1,d+1,mxd);
		if(flag)return ;
	}
}
bool check(int x1){
	//cout<<"x="<<x1<<endl;
	x=x1;
	flag=0;
	for(int rt=1;rt<=n;rt++){
		//cout<<"rt="<<rt<<":\n";
		dfs1(rt,0);
		/*for(int i=1;i<=n;i++)cout<<s[i]<<" ";
		cout<<endl;
		for(int i=1;i<=n;i++)cout<<h[i]<<" ";
		cout<<endl;*/
		for(int v:e[rt]){
			if(!s[v]&&e[v].size()!=1)continue;
			dfs2(rt,0,v,1,2*x+1);
			if(flag)return 1;
		}
	}
	return 0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	h[0]=-1;
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1,u,v;i<n;i++){
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(n==k){printf("0\n");continue;}
		//cout<<check(1)<<endl;
		//return 0;
		int l=1,r=n,mid;
		while(l<r){
			mid=(l+r)>>1;
			if(check(mid))r=mid;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}
