#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3,M=3e5+3;

int n,m;
int a[N];
bool vis[M];
int x[M];
int ans[M];
stack<int>st;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	cin>>n>>m;
	memset(x,-1,sizeof x);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(x[a[i]]==-1)x[a[i]]=i;
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(st.top()!=a[j]&&!st.empty()){
					vis[st.top()]=0;
					st.pop();
				}st.pop();
			}
			st.push(a[j]);
			vis[a[j]]=1;
		}
		
		while(!st.empty()){
			//cout<<st.top();
			ans[st.top()]++;st.pop(); 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
	}
	for(int i=1;i<=m;i++){
		cout<<n-x[i]+1<<" ";
	}
	return 0;
}
