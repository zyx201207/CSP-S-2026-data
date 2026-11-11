//GZ-J00052 贵阳市第一中学 敖翔蓝天 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 505
ll n,m,a[N],ans[N];
bool vis[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				ll cnt=j-1;
				while(a[cnt]!=a[j]){
					vis[a[cnt--]]=0;
				}
			}
			vis[a[j]]=1;
		}
		for(int j=1;j<=m;j++){
			if(vis[j]){
				ans[j]++;
			}
		}
		memset(vis,0,sizeof(vis));
	}
	for(int j=1;j<=m;j++){
		cout<<ans[j]<<' ';
	}
	return 0;
}
//____24分 
//胡大佬牛福！
//Trick||Treat!
//J+S=400
