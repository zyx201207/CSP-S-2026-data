#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
const int N =1e5+5;
struct node{
	int x;
	int y;
	int z;
}a[N]; 
int fa[N];
int find(int x){
	if(fa[x]==x)return fa[x];
	return fa[x]=find(fa[x]);
}
void merge(int x,int y,int z){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy){
		fa[fx]=fy;
	} 
} 
int st,ed;
int ans =0; 
void clac(int xf){
	for(int i =m;i<=n+m;i++){
		if(a[i].x==xf)ans+=a[i].z;
	}
}
void solve(){
	ans+=a[st].z;
	int t=st;
	while(fa[t]==ed){
		clac(fa[t]);
		t=fa[t];
	}
	ans+=a[ed].z;
	cout<<ans;
}
bool cmp(node a,node b){
	return a.z<b.z; 
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i =1;i<n+m;i++)fa[i]=i;
	for(int i =1,fx;i<=m;++i){
		cin>>fx;
		a[i].x=0;
		a[i].y=i;
		a[i].z=fx;
	}
	int cnt=m;
	for(int i =1;i<=n;i++){
		int k ;
		cin>>k;
		for(int j=1,xz,yz;j<=k;j++){
			cin>>xz>>yz;
			if(j==1)a[++cnt].x=xz;
			
			if(j!=1)a[++cnt].x=a[cnt-1].y;
			a[cnt].y=xz;
			a[cnt].z=yz;
		}
	}
	int df= 0;
	sort(a+1,a+cnt+1,cmp);
	for(int i =m;i<=m+n;i++){
		int fx=find(a[i].x);
		int fy=find(a[i].y);
		if(fx!=fy){
			fa[fx]=fy;
		} 
	}
	while(q--){
		cin>>st>>ed;
		solve();
		ans=0 ;
	}
} 
