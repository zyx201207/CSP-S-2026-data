#include<bits/stdc++.h>
using namespace std;
int c,q,a[500005];int n,m;
struct node{
	int value,step;//v:ÌôÀ´×î¶ÌÂ·£¬step tongjulidegeshu 
};
node ans[50][50];
int vis[50];
bool isp(){
	int ch=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=ch)return false;
	}
	return true;
}
//void dfs(int now){
//	vis[now]=1;
//	for(int i=)
//}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>q;
	while(q--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(isp()){
			int cha=a[2]-a[1];
		int juli=m/cha;
	//	cout<<a[2]<<" "<<a[1]<<" "<<a[2]-a[1]<<" ";
		cout<<n-2*juli+1<<endl;}
//		}else{
//			for(int i=1;i<=n;i++){
//				dfs
//			} 
//		}
		
	}
	return 0;
} 
