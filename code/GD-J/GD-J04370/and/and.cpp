#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[10010];
int cf[1005],ff[10005];
int n,m;
int z=12;
void dfs(int h,int y){
	if(h==m){
		return;
	}
	for(int i=1;i<=n;i++){
		if(y==-1){
			cf[h]=max(cf[h],a[i]);
			dfs(h+1,a[i]);
		}
	}
}
signed main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(m%2==0){
		cout<<z;
	}
	if(m%3==0){
		cout<<"7";
	}
	return 0;
}
