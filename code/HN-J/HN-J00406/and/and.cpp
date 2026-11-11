#include<bits/stdc++.h>
using namespace std;
int m,n,b,c;
int a[200005],DDD[200005],bb[200005];
int dfs(int x,int y,int z){
	y=int(y&a[x]);
	//cout<<y<<' '<<z<<endl;
	if(z==m) return y;
	int ma=-114514;
	if(DDD[x]>=y) return 0;
	bb[x]=1;
	for(int i=1;i<=n;i++){
		if(bb[i]==0){
			ma=max(ma,dfs(i,y,z+1));
		}
	}
	bb[x]=0;
	DDD[x]=max(DDD[x],ma);
	return DDD[x];
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int dfma=-114514;
	for(int i=1;i<=n;i++){
		dfma=max(dfma,dfs(i,a[i],1));
	}
	cout<<dfma;
	return 0;
}
/*
5 3
31 3 1 15 7
*/
