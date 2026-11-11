#include<bits/stdc++.h>
using namespace std;
void read(int &n){int x=0,f=1;char c=getchar();while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}n=x*f;}
const int N=1e6+5;
int c,t;
int n,k;
vector<int>g[N];
int deep[N];
void cle(){
	for(int i=1;i<=n;i++)g[i].clear();
}
int mark[N];
void dfs(int x,int fa,int w){
	deep[x]=0;
	int cc=0;
	for(int i:g[x]){
		if(i==fa)continue;
		dfs(i,x,w);
		if(mark[i])cc++;
		if(mark[x]!=1&&mark[i])mark[x]=2;
		if(x==1&&(cc>=2||deep[1]+deep[i]+1>=w))mark[x]=1;
		if(deep[i]<w)deep[x]=max(deep[x],deep[i]+1);
	}
	if(deep[x]==w)mark[x]=1,deep[x]=-1;
}
int cnt1,len;
int dfs2(int x,int fa,int w){
	int f1=0,f2=0;
	for(int i:g[x]){
		if(i==fa)continue;
		int tmp=dfs2(i,x,w);
		if(tmp>f1&&mark[x]!=1)f2=f1,f1=tmp;
		else if(tmp>f2)f2=tmp;
	}
	if(mark[x])cnt1++;
	else return 0;
	if(mark[x]==1)len=max(len,f2);
	else len=max(len,f1+f2);
	if(mark[x]==1)return 1;
	else return max(f2,f1)+(mark[x]!=0);
}
void dfs3(int x,int fa){
	if(mark[x]==1)return;
	mark[x]=0;
	for(int i:g[x]){
		if(i==fa)continue;
		dfs3(i,x);
	}
}
bool solve(int x){
	for(int i=1;i<=n;i++)mark[i]=0;
	dfs(1,0,x);
	cnt1=0;len=0;
	dfs3(1,0);
//	cout<<x<<' '<<deep[1]<<endl; 
//	for(int i=1;i<=n;i++)cout<<mark[i]<<' ';cout<<endl;
	dfs2(1,0,x);
	if(mark[1]!=1){
		dfs3(1,0);
	}
//	cout<<len<<endl;
//	if(cnt1>k)return 0;
	if(cnt1-min(len-1,2*x-1)<=k)return 1;
	else return 0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	read(c);read(t);
	while(t--){
		read(n);read(k);
		for(int u,v,i=1;i<n;i++){
			read(u);read(v);g[u].push_back(v);g[v].push_back(u);
		}
		int l=1,r=n-1,mid,ans=n-1;
		while(l<=r){
			mid=(l+r)/2;
			if(solve(mid)){
				r=mid-1;ans=mid;
			}else{
				l=mid+1;
			}
		}
		cout<<ans<<endl;
		cle();
	}
	return 0; 
}
/*
0 1
5 2
1 2
2 3
3 4
4 5
*/
