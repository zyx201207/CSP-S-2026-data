#include<bits/stdc++.h>
using namespace std;
long long a[510][50500];
int c,n,m,d,q,k,cc[5010];
int x,y,ss,fr,zz;
void dfs(int xx,int yy,int z,int fd){
	if(xx>=yy) {
		z+=fd;
		ss=min(ss,z);
		cout<<fd<<endl;
		return ;	
	}
	z+=fd;
	cout<<fd<<" ";
	for(int i=1;i<=n;i++){
		if(a[i][xx]!=0){
			for(int j=1+xx;j<=yy;j++){
				if(a[i][j]!=0){
					cout<<z<<" ";
					dfs(j,yy,z,a[i][xx]+a[i][j]);
				} 
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m;
	cin>>d>>q;
	for(int i=1;i<=m;i++) cin>>cc[i];
	for(int i=1;i<=n;i++) {
		cin>>k;
		for(int j=1;j<=k;j++) {
			cin>>fr;
			cin>>a[i][fr]; 
		}
	}
	while(q--){
		cin>>x>>y;
		ss=INT_MAX;
		dfs(x,y,zz,0);
		ss+=(cc[x]+cc[y]);
		cout<<ss<<endl;
	}
	return 0;
} 
