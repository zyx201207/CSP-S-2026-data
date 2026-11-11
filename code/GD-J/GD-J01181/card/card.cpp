#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],vis[300005],t[300005];
stack<int> pd,js;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
		if(t[a[i]]==0){t[a[i]]++;pd.push(a[i]);}
		else{
			while(pd.top()!=a[i]){
				t[pd.top()]--;
				pd.pop();
			}
		}
		while(!pd.empty()){
			js.push(pd.top());
			vis[pd.top()]++;
			pd.pop();
		}
		while(!js.empty()){
			pd.push(js.top());
			js.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<vis[i]<<" ";
	}
	return 0;
} 
