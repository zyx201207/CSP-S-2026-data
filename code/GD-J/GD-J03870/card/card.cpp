#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bool vis[300005];
		stack<int>s;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(s.top()!=a[j]){
					vis[s.top()]=0;
					s.pop();
				}
				if(s.top()==a[j])s.pop();
			}
			s.push(a[j]);
			vis[a[j]]=1;
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
