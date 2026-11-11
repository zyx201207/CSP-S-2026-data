#include<bits/stdc++.h>
using namespace std;
stack<int>st;
int vis[300005],a[500005],ans[300005];
int pre1[500005],pre2[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	int op=1;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		pre1[i]=pre1[i-1];
		pre2[i]=pre2[i-1];
		if(a[i]==1)++pre1[i];
		else ++pre2[i];
		if(a[i]>2)op=0;
	}
//	if(op==1){
//		if(a[n]==2)return cout<<"0 "<<n,0;
//		else return cout<<n<<" 0",0;
//	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)vis[j]=0;
		while(!st.empty())st.pop();
		for(int j=i;j<=n;++j){
			if(st.empty()){
				st.push(a[j]);++vis[a[j]];
				continue;
			}
			if(vis[a[j]]!=0){
				while(st.top()!=a[j]){
					--vis[st.top()];
					st.pop();
				}
			}
			st.push(a[j]);++vis[a[j]];
		}
		for(int j=1;j<=m;++j){
			if(vis[j]!=0)++ans[j];
//			cout<<vis[j]<<" ";
		}
	}
	for(int i=1;i<=m;++i)cout<<ans[i]<<" ";
	return 0;
}
