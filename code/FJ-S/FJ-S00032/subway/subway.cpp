#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5;
long long c,n,m,d,q,t[N],k[N],l[N][N],ans=INT_MAX,id[N];
vector<long long>a[N];
void dfs(int step,long long x,long long now,int end){
	now+=l[x][id[x]];
	if(x==end){
		ans=min(ans,now);
		return;
	}
	
	if(a[x].empty())return;
	int cnt=0;
	for(int v:a[x]){
		if(id[x]!=id[v])dfs(step+1,v,now+l[x][id[x]],end);
		else dfs(step+1,v,now,end);
	}
}
long long read(){
	long long x=0;
	int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++){
		t[i]=read();
	}

	for(int i=1;i<=n;i++){
		long long x;
		x=read();
		for(int j=1;j<=x;j++){
			long long u;
			cin>>k[j]>>l[k[j]][i];
			id[k[j]]=i;
		}
		for(int j=1;j<x;j++){
			a[j].push_back(k[j+1]);
		}
	}
	while(q--){
		long long x,y;
		x=read();
		y=read();
		ans=INT_MAX;
		dfs(0,x,0,y);
		ans+=t[x];
		ans+=t[y];
		cout<<ans<<'\n';
	}
	return 0;
}
