#include<bits/stdc++.h>
using namespace std;
int C,T;
int n,k;
int x[6];
vector<int> a[2000001];
int ki[2000001],kj;
void bian(int vv,int uu){
	a[vv].push_back(uu);
	a[uu].push_back(vv);
}
int dfs(int dd,int fa){
	int de=1,dei;
	for(int i=0;i<a[dd].size();i++){
		if(a[dd][i]!=fa) dei=dfs(a[dd][i],dd)+1;
		if(de<dei){
			de=dei;
		}
	}
	return de;
}
int ddfs(int dd1,int dd2,int fa){
	int bl=0;
	if(dd1==dd2){
		ki[++kj]=dd1;
		return 1;
	}
	for(int i=0;i<a[dd1].size();i++){
		if(a[dd1][i]!=fa) bl=ddfs(a[dd1][i],dd2,dd1);
		if(bl==1){
			ki[++kj]=dd1;
			return 1;
		}
	}
}
int hub(int nn,int kk){
	int v,u,xx;
	for(int i=1;i<=nn;i++){
		cin>>v>>u;
		bian(v,u);
	}
	int d1=dfs(1,0);
	int d2=dfs(d1,0);
	ddfs(d1,d2,0);
	for(int i=1;i<=kj;i++) xx+=ki[i];
	return xx;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>C>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>k;
		x[i]=hub(n,k);
		for(int j=1;j<=n;j++) a[j].clear();
	}
	for(int i=1;i<=n;i++) cout<<x[i]<<"\n";
	return 0;
} 

