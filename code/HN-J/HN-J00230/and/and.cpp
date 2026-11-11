#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
int a[2050],f[2050];
void bfs(int step,int s){
	if(step>m) ans=max(ans,s);
	for(int i=1;i<=n;i++){
		if(f[i]) continue;
		f[i]=1;
		bfs(step+1,s&a[i]);
		f[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	bfs(1,2147483647);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
