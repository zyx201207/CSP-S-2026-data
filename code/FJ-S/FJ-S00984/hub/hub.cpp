#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int u;
	int v;
	int w;
}a[1000005];
bool cmp(node a,node b){
	return a.w>b.w;
}
int fa[1000005];
int find_(int x){
	if(fa[x]==x) return x;
	fa[x]=find_(fa[x]);
	return fa[x];
}
void union_(int u,int v){
	int fa1=find_(u),fa2=find_(v);
	fa[fa2]=fa1;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>a[i].u>>a[i].v>>a[i].w;
		for(int i=1;i<=n;i++) fa[i]=i;
		sort(a+1,a+n+1,cmp);
		int cnt=0;
		int maxn=-1;
		for(int i=1;i<=n;i++){
			if(cnt==k-1) break;
			if(find_(a[i].u)!=find_(a[i].v)){
				cnt++,maxn=a[i].w;
				union_(a[i].u,a[i].v);
			}
		}
		cout<<maxn<<endl;
	} 
	return 0;
}
//¿¨ÆÀ²â 
