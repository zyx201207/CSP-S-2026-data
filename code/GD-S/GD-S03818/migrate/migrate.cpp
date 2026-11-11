#include<bits/stdc++.h>
using namespace std;
int q,c,n,d;
int yn=0;
long long ans;
int a[100005];
void dfs(int x,int y,int z){
	int aaaa=0;
	for(int k=1;k<=n;k++) if(a[k]==y) aaaa=1;
	if(aaaa=0) return ; 
	if(z==2) {
		yn=1;
		return ;
	}
	if(y==x) {
		dfs(x,a[1],z+1);
		return ;
	}
	for(int i=1;i<=d;i++){
		dfs(x,y+i,z);
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>q;
	for(int e=1;e<=q;e++){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			dfs(i,a[1],0);
			if(yn==1) ans++;
			yn=0;
		}
		cout<<ans<<endl;
	} 
	return 0;
}
