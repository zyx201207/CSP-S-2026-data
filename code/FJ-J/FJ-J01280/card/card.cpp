#include<bits/stdc++.h>
using namespace std; 
const int N=5e5;
int cnt[N+5];//桌面上留有点数为 i 的牌的局数 
int a[N+5];
int vis[N+5];//点数是否出现过 
deque<int> dq;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	memset(cnt,0,sizeof cnt);
	//n局游戏 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int k=a[j];
			if(vis[k]==1){
				while(dq.back()!=k){
					vis[dq.back()]=0;
					dq.pop_back();
				}
			}else{
				dq.push_back(k);
				vis[k]=1;
			}
		}
		while(!dq.empty()){
			cnt[dq.back()]++;
			vis[dq.back()]=0;
			dq.pop_back();
		}
	}	
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	//Ich verliebe mich in zmj. 
	return 0;
}
