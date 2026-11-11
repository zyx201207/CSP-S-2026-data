#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=10050;
int cnt[N],a[N];
bool vis[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>0;i--){
		stack<int>stk;
		memset(vis,0,sizeof vis);
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==1){
				while(stk.top()!=a[j]){
					stk.pop();
				}
				stk.pop();
			}
			stk.push(a[j]);
			vis[a[j]]=1;
		}
		while(stk.size()){
			cnt[stk.top()]++;
			stk.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" "; 
	}
	return 0;
}
/*
4 3
1 2 1 3
*/
