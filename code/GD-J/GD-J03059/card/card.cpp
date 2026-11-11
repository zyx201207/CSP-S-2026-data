#include<bits/stdc++.h>
using namespace std;
int a[500005],cnt[300005];
bool vis[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
int n,m;
cin>>n>>m;	
for(int i=1;i<=n;i++){
	cin>>a[i];
}
for(int i=1;i<=n;i++){
	stack<int> st;
	memset(vis,0,sizeof(vis));
	for(int j=i;j<=n;j++){
		if(!vis[a[j]]){
			vis[a[j]]=1;
			cnt[a[j]]++;
			st.push(a[j]);
		}
		else{
			while(st.top()!=a[j]){
				cnt[st.top()]--;
//				cout<<st.top()<<" ";
				st.pop();
			}
		}
	}
	
}
for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0; 
}
