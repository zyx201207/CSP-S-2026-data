#include<bits/stdc++.h>
#define int long long
const int N=5e5+10;
const int INF=0x3f3f3f3f; 
using namespace std;
int n,m;
int a[N];
int ans[N];//记录答案 
int vis[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){//枚举每一局
		memset(vis,0,sizeof(vis));
		int l=i; //留下来最左边的牌 
		for(int j=i;j<=n;j++){//找到留下来最左边的牌 
			if(vis[a[j]]==1){
				l=j;
				memset(vis,0,sizeof(vis));
			}
			vis[a[j]]=1;
		} 
		for(int j=l;j<=n;j++){
			ans[a[j]]++;
		} 
//		for(int j=l;j<=n;j++){
//			cout<<a[j]<<" ";
//		}cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
