#include<bits/stdc++.h>
using namespace std; 
using ll=long long;
ll n,m,a[500010],vis[500010],cnt[300010],flaga=1;
void solve(ll x){
	stack<ll>st;
	for(int i=x;i<=n;i++){
		if(vis[a[i]]==1){
			while(st.top()!=a[i]&&!st.empty()){
				st.pop();
			}
		}
		else{
			vis[a[i]]=1;
			st.push(a[i]);
		}
	}
	while(!st.empty()){
		cout<<st.top()<<' ';
		cnt[st.top()]++;
		st.pop();
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i])flaga=0;
	}
	if(flaga==1){
		ll cur=0;
		for(int i=1;i<=n;i++){
			cnt[a[i]]++;
		}
		cout<<cnt[1]<<' ';
		for(int i=2;i<=m;i++){
			cnt[i]+=cnt[i-1];
			cout<<cnt[i]<<' ';
		}
	}
	else{
		for(int x=1;x<=n;x++){
			solve(x);
			memset(vis,0,sizeof(vis));
		}
		for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
	}
	return 0;
}//10 3 3 1 2 1 3 2 3 1 2 1
