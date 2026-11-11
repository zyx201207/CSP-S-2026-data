#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+7;
bool vis[maxn];
int a[maxn],cnt[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	stack<int>s;
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		while(!s.empty()){
			cnt[s.top()]++;
			s.pop();
		}
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(!s.empty() && s.top()!=a[j])s.pop();
				if(!s.empty() && s.top()==a[j])s.pop();
			}
			s.push(a[j]);
			vis[a[j]]=1;
		}
	}
	while(!s.empty()){
		cnt[s.top()]++;
		s.pop();
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
