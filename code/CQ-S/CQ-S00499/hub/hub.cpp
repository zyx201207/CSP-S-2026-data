#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
int C,T,n,k,sum,top,maxn,maxi,flag,fa[N],st[N],len[N],del[N],dis[N];
vector<int> a[N];
void dfs(int x,int prt){
	fa[x]=prt;
	for(int i:a[x]){
		if(i==prt)continue;
		dfs(i,x);
	}
}
void dfs2(int x,int prt,int d){
	if(d>maxn){
		maxn=d;
		maxi=x;
	}
	for(int i:a[x]){
		if(i==prt||del[i])continue;
		dfs2(i,x,d+1);
	}
}
void fid(int x,int prt,int t){
	st[++top]=x;
	if(x==t){
		flag=1;
		return;
	}
	for(int i:a[x]){
		if(i==prt||del[i])continue;
		fid(i,x,t);
		if(flag)return;
	}
	top--;
}
void dfs3(int x,int prt,int d){
	len[x]=0;
	for(int i:a[x]){
		if(i==prt||del[i])continue;
		dfs3(i,x,d);
		len[x]=max(len[x],len[i]+1);
	}
	// printf("%d:%d\n",x,len[x]);
	if(len[x]>=d)sum++;
}
bool check(int d){
	if(k<=2){
		maxn=-1;
		dfs2(1,0,0);
		int x=maxi;
		maxn=-1;
		dfs2(x,0,0);
		top=flag=0;
		fid(x,0,maxi);
		if(d*2>=top)return 1;
		queue<int> q;
		q.push(st[d]);
		q.push(st[top-d]);
		for(int i=1;i<=n;i++)dis[i]=-1;
		int mx=0;
		while(q.size()){
			int x=q.front();
			q.pop();
			mx=max(mx,dis[x]);
			for(int i:a[x]){
				if(dis[i]<0){
					dis[i]=dis[x]+1;
					q.push(i);
				}
			}
		}
		return mx<=d;
	}
	for(int i=1;i<=n;i++){
		if(!fa[i])continue;
		del[fa[i]]=1;
		maxn=-1;
		dfs2(i,0,0);
		maxn=-1;
		int x=maxi;
		dfs2(x,0,0);
		top=sum=flag=0;
		fid(x,0,maxi);
		// printf("%d\n",st[top/2+1]);
		dfs3(st[top/2+1],0,d);
		del[fa[i]]=0;
		del[i]=1;
		maxn=-1;
		dfs2(fa[i],0,0);
		maxn=-1;
		x=maxi;
		dfs2(x,0,0);
		top=flag=0;
		fid(x,0,maxi);
		// printf("%d\n",st[top/2+1]);
		dfs3(st[top/2+1],0,d);
		del[i]=0;
		// printf("---%d %d %d %d\n",i,fa[i],s,sum);
		if(sum<=k)return 1;
	}
	return 0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&C,&T);
	while(T--){
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;i++){
			a[i].clear();
		}
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			a[x].push_back(y);
			a[y].push_back(x);
		}
		dfs(1,0);
		// printf("%d\n",check(2));
		int l=0,r=n;
		while(l<r){
			int mid=l+r>>1;
			if(check(mid))r=mid;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}