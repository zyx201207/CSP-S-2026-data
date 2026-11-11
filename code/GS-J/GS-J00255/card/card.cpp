#include<bits/stdc++.h>
using namespace std;
const int MAXN=500002;
const int MAXM=300002;
int ans[MAXM]; // ans[i]:有几局剩下的有i 
int n; // 牌的数量
int m; //  点数种类数
deque<int>desk; // 桌子
int a[MAXN];
bool vis[MAXN];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				vis[a[j]]=1;
				desk.push_back(a[j]);
			}else{
				while(desk.front()!=a[j]){
					vis[desk.front()]=0;
					desk.pop_front();
				}
				desk.pop_front();
				desk.pop_front();
				desk.push_back(a[j]);
				vis[a[j]]=1;
			}
		}
		while(!desk.empty()){
			ans[desk.back()]++;
			desk.pop_back();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" \n"[i==m];
	}
	return 0;
}
