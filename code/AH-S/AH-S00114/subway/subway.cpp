#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long ans=0x3f3f3f3f,w[500010],a[510][500010],t[510][500010];
int k[500010];
void dfs(long long he,int x,int y){
	if(x==y){
		ans=min(ans,he);
		return;
	}
	for(int j=0;j<k[x];j++){
		if(a[x-1][j]<=n||a[x-1][j]==y){
			dfs(he+t[x-1][j],a[x-1][j]-1,y);
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	long long h=0;
	for(int i=0;i<q;i++){
		h=0;
		int x,y,flag=1;
		cin>>x>>y;
		h+=w[x]+w[y]+t[x-1][0];
		for(int z=0;z<k[x-1];z++){
			if(a[x-1][z]==y){
				h+=t[x-1][z];
				flag=0;
			}
		}
		if(flag==1){
			dfs(0,x-1,y-1);
		}
		cout<<h<<endl;
	}
	return 0;
}
