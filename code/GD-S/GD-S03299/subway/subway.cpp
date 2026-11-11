#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[500005],ans,vv[50005][505];
bool ds[500005];
struct aa{
	int z,t;
};
vector<aa> v[505];
vector<int> zpx[500005];
inline int read(){
	int _=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		_=_*10+ch-'0';
		ch=getchar();
	}
	return _*f;
}
inline void dfs(int x,int y,int time,int xian){
	if(x==y){
		time+=w[y];
		ans=min(ans,time);
		return ;
	}
	if(xian==0) time+=w[x];
	for(int i=0;i<zpx[x].size();i++){
		xian=zpx[x][i];
		int t_=vv[x][xian];
		time+=t_;
		for(int j=0;j<v[xian].size();j++){
			if(!ds[v[xian][j].z]&&v[xian][j].z!=x){
				ds[v[xian][j].z]=1;
				time+=v[xian][j].t;
				dfs(v[xian][j].z,y,time,xian);
				time-=v[xian][j].t;
				ds[v[xian][j].z]=0;
			}
		}
		time-=t_;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		int x=read();
		for(int j=1;j<=x;j++){
			int _=read(),__=read();
			v[i].push_back({_,__});
			vv[_][i]=__;
			zpx[_].push_back(i);
		}
	} 
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ans=INT_MAX;
		memset(ds,0,sizeof(ds));
		dfs(x,y,0,0);
		cout<<ans<<endl;
	}
	return 0;
}

