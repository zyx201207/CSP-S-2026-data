#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int ans[300001]; 
int a[500001],moni[500001],vis[300001];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--)if(!vis[a[i]])vis[a[i]]=i;
	for(int i=1;i<=n;i++){
		int u=i;
		while(u<=n){
			ans[a[u]]++;
			u=vis[a[u]]+1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
/*
退役前最后一场了，T4还不会，打个80pts跑路，估分380，
个人感觉T4>T2>T3>T1
S组不要炸掉 
应该是红橙橙黄
但我不能场黄欸

这个随机数据下跑得还蛮快的
希望不会出123456……m m m……n 之类的数据... 
理论O(NM)来着。 
*/
