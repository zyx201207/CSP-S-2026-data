#include<bits/stdc++.h>
using namespace std;
int a[500010];
bool vis[300010];
stack<int> s;
int ans[300010];
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			if(vis[a[i]]){
				while(!s.empty()&&s.top()!=a[i]){
					vis[s.top()]=0;
					s.pop();
				}	
			}
			vis[a[i]]=1;
			s.push(a[i]);
		}
		for(int i=1;i<=m;i++){
			ans[i]+=vis[i];
			vis[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
