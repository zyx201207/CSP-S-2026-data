#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,y,x,rx,ry;
int w[1010],u[1010][1010],a[1010],t[1010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			u[i][j]=u[i][j]=9999999;
		}
	}
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int j=0;j<k;++j){
			cin>>x>>y;
			a[j]=x;
			t[j]=y;
		}
		for(int j=0;j<k;++j){
			for(int s=j+1;s<k;++s){
				u[a[j]][a[s]]=u[a[s]][a[j]]=min(t[j]+t[s],u[a[j]][a[s]]);
			}
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=m;++j){
			for(int k=1;k<=m;++k){
				u[k][i]=u[i][k]=min(u[i][k],u[i][j]+u[i][k]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>rx>>ry;
		cout<<u[rx][ry]+w[rx]+w[ry]<<endl;
	}
	return 0;
}
