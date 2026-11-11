/*
I AK CSP!!!
I AK CSP!!!
I AK CSP!!!
*/
//100+100+55+48=303pts
//stack? n*(n+m) 48pts
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],ans[300005];
bool vis[300005];
stack<int> stk;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				stk.push(a[j]);
				vis[a[j]]=1;
			}else{
				while(stk.top()!=a[j]){
					int t=stk.top();
					vis[t]=0;
					stk.pop();
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(vis[i]){
				ans[i]++;
				vis[i]=0;
			}
		}
		while(!stk.empty()){
			stk.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*
I AK CSP!!!
I AK CSP!!!
I AK CSP!!!
*/ 
