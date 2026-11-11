#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long cnt;
int ans;
long long a[500050];
int fa[500050];
int ge[500050];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
long long qv[500050];
void merge(int x,int y){
	x=find(x);
	y=find(y);
    fa[x]=y;
    ge[y]+=ge[x];
    qv[y]+=qv[x]+(a[y]-a[x])*ge[x];
}
struct node{
	long long c;
	int l,r;
	bool operator<(const node &rhs) const{
		if(c!=rhs.c){
			return c<rhs.c;
		} else{
			return l<rhs.l;
		}
	}
}b[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		fa[i]=i;
		ge[i]=1;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++){
		b[i].c=a[i+1]-a[i];
		b[i].l=i;
		b[i].r=i+1;
	}
	sort(b+1,b+n);
	for(int i=1;i<=n;i++){
		if(find(b[i].l)!=find(b[i].r)){
			int xxx=ge[fa[b[i].l]],yyy=ge[fa[b[i].r]];
			merge(b[i].l,b[i].r); 
		}
	}
	for(int i=1;i<=n;i++){
		if(qv[b[i].r]<=m){
			ans=max(ans,ge[b[i].r]);
		}
	}
	cout<<ans;
	return 0;
} 
