#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m,mx=0x3f3f3f3f3f3f;
bool bj[200005];
void dfs(long long nx,long long res){
	if(nx>=m){
		mx=max(mx,res);
		return ;
	}
	for(int i=0;i<n;i++){
		if(bj[i]!=1){
			bj[i]=1;
			int ls=(res&a[i]);
			dfs(nx+1,ls);
			bj[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,INT_MAX);
	cout<<mx;
	return 0;
}
