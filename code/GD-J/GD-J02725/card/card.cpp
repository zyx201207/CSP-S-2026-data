#include<bits/stdc++.h>
using namespace std;
int n,m,ans[5005],a[5005],vis[5005];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(!st.empty()){
					vis[st.top()]=0;
					if(st.top()==a[i]){
						cout<<st.top()<<endl;
						st.pop();
						break;
					}
					st.pop();
				}
			}
			st.push(a[j]);
			vis[a[j]]=1;
		}
		while(!st.empty()){
			cout<<st.top()<<endl;
			ans[st.top()]++;
			vis[st.top()]=0;
			st.pop();
		}
		for(int i=0;i<=5000;i++){
			vis[i]=0;
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
