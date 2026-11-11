#include<Bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
struct node{
	int s,x,id,step;
};
int n,m,a[N],ans=0;
queue<node>q;
map<int,map<int,int> >vis;
int read(){
	int f=1,x=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+(c^48),c=getchar();
	return f*x;
}
bool cmp(int a,int b){
	return a>b;
}
void bfs(){
	for(int i=1;i<=n-m+1;i++) q.push(node{a[i],a[i],i+1,1});
	while(!q.empty()){
		node u=q.front();
		q.pop();
		if(u.step==m){
			ans=max(ans,u.x);
			continue;
		}
		if(u.step>=1&&u.x<vis[u.s][u.step]) continue;
		int k=n-m+u.step+1;
		for(int i=u.id;i<=k;i++)
			if((u.x&a[i])>vis[u.s][u.step+1]&&(u.x&a[i])>ans){
				q.push(node{u.s,u.x&a[i],i+1,u.step+1});
				vis[u.s][u.step+1]=u.x&a[i];
			}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n,cmp);
	bfs();
	cout<<ans;
	return 0;
}
