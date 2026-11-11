#include<bits/stdc++.h>
#define int long long
using namespace std;
int read();
struct node{
	int l,r;
}c[1000010];
int C,t,n,k,maxk,maxn,v[1000010],d[1000010],ans,cnt,sum;
vector<int>a[1000010],b;
bool cmp(node x,node y){
	return x.r<y.r;
}
void dfs(int x,int p,int s){
	if(s>maxn){
		maxk=x;
		maxn=s;
	}
	for(int i=0;i<a[x].size();i++){
		if(a[x][i]==p)continue;
		dfs(a[x][i],x,s+1);
	}
}
bool find(int x,int p,int y){
	if(x==y){
		b.push_back(x);
		v[x]=1;
		return 1;
	}
	for(int i=0;i<a[x].size();i++){
		if(a[x][i]==p)continue;
		if(find(a[x][i],x,y)){
			b.push_back(x);
			v[x]=1;
			return 1;
		}
	}
	return 0;
}
void dfs1(int x,int p,int m){
	d[x]=0;
	for(int i=0;i<a[x].size();i++){
		if(a[x][i]==p)continue;
		dfs1(a[x][i],x,m);
		d[x]=max(d[x],d[a[x][i]]+1);
	}
	if(d[x]>=m)sum++;
}
bool check(int x){
	if(x+x+1>=b.size())return 1;
	cnt=0;
	sum=0;
	for(int i=x+1;i<b.size()-x-1;i++){
		d[b[i]]=0;
		for(int j=0;j<a[b[i]].size();j++){
			if(v[a[b[i]][j]])continue;
			dfs1(a[b[i]][j],b[i],x);
			d[b[i]]=max(d[b[i]],d[a[b[i]][j]]+1);
		}
		if(d[b[i]]>=x)c[cnt++]={i,i};
		else{
			c[cnt++]={i-(x-d[b[i]]),i+(x-d[b[i]])};
		}
	}
	ans=b.size()-x-x+sum;
	sort(c,c+cnt,cmp);
	int mm=x,j=0;
	for(int i=x+1;i<b.size()-x-1;i++){
		while(j<cnt&&c[j].r==i){
			mm=max(mm,c[j].l);
			j++;
		}
		ans=min(ans,mm-x+1+b.size()-x-i-1+sum);
	}
	return ans<=k;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			a[i].clear();
			v[i]=0;
		}
		b.clear();
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			a[u].push_back(v);
			a[v].push_back(u);
		}
		maxn=0;
		dfs(1,0,0);
		int bb=maxk;
		maxn=0;
		dfs(bb,0,0);
		find(bb,0,maxk);
		int l=0,r=n;
		while(l<r){
			int mid=(l+r)/2;
			if(check(mid))r=mid;
			else l=mid+1;
		}
		cout<<l<<endl;
	}
	return 0;
}
int read(){
	int s=0,sg=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')sg=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*sg;
}