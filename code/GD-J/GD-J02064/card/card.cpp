#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int ans[N],vis[N],cnt[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n<=500&&m<=200){
	for(int i=1;i<=n;i++){
		cin>>ans[i]; 
	}
//	return 0;
	stack<int>q;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int x=ans[j];
			if(vis[x]){
				while(!q.empty()){
					int id=q.top();
					q.pop();
					vis[id]=0;
					if(id==x)break;
				}
			}
			q.push(x);
			vis[x]=1;
		}
//		return 0;
		while(!q.empty()){
			cnt[q.top()]++;
			q.pop();
		}
		for(int i=1;i<=m;i++)vis[i]=0;
//		for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
//		cout<<'\n';
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
	}else{
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			ans[x]++; 
		} 
		for(int i=1;i<=m;i++){
			ans[i]+=ans[i-1];
			cout<<ans[i]<<' ';
		}
	}
	return 0;
}/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
