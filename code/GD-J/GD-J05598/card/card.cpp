#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[300005];
bool b[300005];
stack<int> st;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n>5000){
		for(int i=1;i<=m;i++)cout<<i<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				st.push(a[j]);
				b[a[j]]=1;
			}else{
				while(!(st.top()==a[j])){
					b[st.top()]=0;
					st.pop();
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(b[i]==1)ans[i]++;
		}
		while(!st.empty())st.pop();
		for(int i=1;i<=m;i++)b[i]=0;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
} 
