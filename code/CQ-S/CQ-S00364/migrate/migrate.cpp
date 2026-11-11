#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
ll n,d;
ll a[N];
int ed;
int ans1,ans2;
void dfs(int u,int len){
	if(u==ed){
		if(ans1>len){
			ans1=len;
			ans2=1;
		}else if(ans1==len){
			ans2++;
		}
		return;
	}
	for(int v=u+1;v<=n;v++){
		if(a[v]-a[u]>d)break;
		dfs(v,len+1);
	}
}
void sol(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ed=j;
			ans1=0x3f3f3f3f,ans2=0;
			dfs(i,0);
			if(ans2==2)ans++;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	freopen("migrate2.in","r",stdin);
//	freopen("dma.out","w",stdout);
	int ceshi,t;
	cin>>ceshi>>t;
	while(t--){
		sol();
	}
	return 0; 
}
/*
struct A{
	int l,r;
}bb[N],b[N];
	int zz=1;
	a[n+1]=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n;i++){
		bb[i].l=i;
		while(a[zz+1]-a[i]<=d)zz++;
		bb[i].r=zz;
	}
	int m=0;
	for(int i=1;i<=n;i++){
		if(bb[i].r>bb[i-1].r)b[++m]=bb[i];
	}

*/
