#include<bits\stdc++.h>
using namespace std;
int n,m;

	int a[200005];
	bool check[200005];
	int ans;
void bfs(int aa,int ma){
	if(aa==m+1){
		ans=max(ans,ma);
		return ;
	}
	int zun=ma;
	if(ma==0){
		for(int i=1;i<=n;i++){
			zun=a[i];
			check[zun]=1;
			bfs(aa+1,zun);
			check[zun]=0;
		}
	}
	for(int i=1;i<=n;i++){
		if(!check[a[i]]){
			check[a[i]]=1;
			zun=(zun&a[i]);
			bfs(aa+1,zun);
			check[a[i]]=0;
		zun=ma;
		}
		
	}
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
		cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
			}
		bfs(1,0);
	cout<<ans;
	return 0;
}
