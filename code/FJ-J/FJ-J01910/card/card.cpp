#include<bits/stdc++.h>
using namespace std;
const int MAXN=5E5+5;
int n,m;
int a[MAXN];
unordered_map<int,int>mp;
bool vis[300005];
stack<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i){//第n局游戏
		for(int j=i;j<=n;++j){//出牌
			if(vis[a[j]]==0){
				s.push(a[j]);
				vis[a[j]]=1;
			}else{
				while(!s.empty()&&s.top()!=a[j]){
					vis[s.top()]=0;
					s.pop();
				}
				if(!s.empty())s.pop();
				s.push(a[j]); 
			}
		}
		while(!s.empty()){
			mp[s.top()]++;
			vis[s.top()]=0;
			s.pop();
		}
	}
	for(int i=1;i<=m;++i)cout<<mp[i]<<' ';
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
