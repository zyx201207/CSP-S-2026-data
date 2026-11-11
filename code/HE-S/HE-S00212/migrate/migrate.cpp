#include<bits/stdc++.h>
using namespace std;
struct fly{long long a,s;};
int c,t;
const int MAXN=2e6+800;
long long sid[MAXN];
bool vis[MAXN];
bool is_too(int x,int y,long long r,int n){
	memset(vis,0,sizeof(vis));
	queue<fly> q;
	q.push({0,x});
	vis[x]=1;
	long long u=0,k=0;bool flag=0;
	while(!q.empty()){
		int p=q.front().s;
		long long a=q.front().a;
		for(int i=p+1;i<=n;++i){
			if(sid[i]-sid[p]<=r){
				if(i==y){
					if(!flag){u++;k=a+1;flag=1;}
					else if(a+1==k) u++;
					continue;
				}
				if(!vis[i]||(a+1<=k&&flag)) {q.push({a+1,i});vis[i]=1;}
			}
			else break;
		}
		for(int i=p-1;i>=1;--i){
			if(sid[p]-sid[i]<=r){
				if(i==y){
					if(!flag){u++;k=a+1;flag=1;}
					else if(a+1==k) u++;
					continue;
				}
				if(!vis[i]||(a+1<=k&&flag)) {q.push({a+1,i});vis[i]=1;}
			}
			else break;
		}
		q.pop();
	}
//	cout<<u<<endl;
	if(u==2) return 1;
	else return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int op=1;op<=t;++op){
		int n;long long r;cin>>n>>r;
		for(int i=1;i<=n;++i) cin>>sid[i];
		long long ans=0;
		for(int x=1;x<=n;++x){
			for(int y=x+1;y<=n;++y){
				ans=ans+is_too(x,y,r,n);
			}
		} 
		cout<<ans<<endl;
	}
	return 0;
}
