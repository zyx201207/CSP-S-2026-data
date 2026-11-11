#include<bits/stdc++.h>
using namespace std;
int t,n,l[2000002],r[2000002],w[6];
long long d,a[2000002],f[2000002][6],ans;
queue<int>q,p;
int dfs(int a,int b,int c){
	if(r[a]){
		return 0;
	}
	if(a==b&&b==c){
		return 0;
	}
	int s=0,g=0;
	if(a==b){
		g=1;
	}
	if(!c){
		if(g){
			g=4;
		}
		else{
			g=2;
		}
	}
	if(!b){
		g=3;
	}
	else if(b==c){
		g=5;
	}
	if(f[a][g]!=-1){
		return f[a][g];
	}
	memset(w,0,sizeof(w));
	w[0]=l[a];
	if(l[a]-1>a){
		w[1]=l[a]-1;
	}
	if(l[a]-2>a){
		w[2]=l[a]-2;
	}
	if(b){
		w[3]=l[b];
		if(l[b]-1>b){
			w[4]=l[b]-1;
		}
	}
	if(c){
		w[5]=l[c];
		s=l[b]-max(a,l[c]);
	}
	else if(b){
		s=l[b]-a;
	}
	sort(w,w+6);
	long long p=s+dfs(w[5],w[4],w[3]);
	f[a][g]=p;
	return p;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&n,&t);
	while(t--){
		ans=0;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			memset(f[i],-1,sizeof(f[i]));
		}
		a[n+1]=4999999999999999999;
		for(int i=1;i<=n;i++){
			q.push(i);
			while(!q.empty()&&a[i+1]>a[q.front()]+d){
				l[q.front()]=i;
				q.pop();
			}
			if(a[i]+d<a[i+1]){
				r[i]=1;
			}
			else{
				r[i]=0;
			}
		}
		for(int i=1;i<=n;i++){
			ans+=dfs(i,0,0);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
