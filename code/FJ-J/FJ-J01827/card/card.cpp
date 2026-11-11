#include<bits/stdc++.h>
using namespace std;
stack<int> s;
int n,m;
int a[500005];
bool vis[300005];
int ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				vis[a[j]]=1;
				s.push(a[j]);
			}
			else{
				while(s.top()!=a[j]){
					vis[s.top()]=0;
					s.pop();
				} 
			}
		}
		while(s.size()!=0){
			ans[s.top()]++;
			vis[s.top()]=0;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
