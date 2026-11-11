#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long 
int n,m,a[200010],p[200010],vis[200010],mx=-1,ma=-1;
int szr(int aaa){
	int sum=1;
	for(int i=1;i<aaa;i++){
		sum*=2;
	}
	return sum;
}
int ad(int aa,int bb){
	string ra,rb;
	int sa=0,sb=0;
	while(aa){
		sa++;
		ra[sa]=aa%2+'0';
		aa=aa/2;
	}
	while(bb){
		sb++;
		rb[sb]=bb%2+'0';
		bb=bb/2;
	}
	int sc=0;
	string rc;
	for(int i=1;i<=min(sa,sb);i++){
		sc++;
		if(ra[i]=='1'&&rb[i]=='1')
		{
			rc[i]='1';
		}else{
			rc[i]='0';
		}
	}
	int cc=0;
	for(int i=1;i<=sc;i++){
		if(rc[i]=='1'){
			cc=cc+szr(i);
		} 
	}
	return cc;
}

void dfs(int x,int id){
	if(x>m){
//		cout<<1;
		for(int i=2;i<=m;i++){
//			cout<<p[i-1]<<" ";
			mx=max(mx,ad(p[i-1],p[i]));
			return;
		}
	}
	for(int i=id+1;i<=n;i++){
		if(vis[x]==0){
//			cout<<x<<' '<<id<<' '<<"vis"<<vis[x]<<' '<<"p"<<p[x]<<' ';
			p[x]=a[i];
			vis[x]=1;
			dfs(x+1,id+i);
			vis[x]=0;	
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	dfs(0,0);
	cout<<mx;
	return 0;
} 
/*5 3
31 3 1 15 7
4 2
3 15 12 12*/
