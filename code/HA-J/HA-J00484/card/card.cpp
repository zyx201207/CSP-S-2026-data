#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int ans[N];
int n,m;
int a[N];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int k=0;k<n;k++){
		bool vis[N]={0};
		for(int i=k;i<n;i++){
			if(!vis[a[i]]){
				st.push(a[i]);
				vis[a[i]]=1;
			}
			while(st.top()!=a[i]){
				vis[st.top()]=0;
				st.pop();
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		} 
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
