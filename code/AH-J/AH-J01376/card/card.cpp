#include<bits/stdc++.h>
using namespace std;
int a[500010];
int vis[300010];
int ans[300010];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    stack<int> st;
    int n,m;
    bool flagA=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>a[i-1]) flagA=1;
	}
	if(flagA==0){
		for(int i=1;i<=m;i++){
			int u=upper_bound(a+1,a+1+n,i)-a-1;
			cout<<u<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				st.push(a[j]);
				vis[a[j]]=1;
			}else{
				while(st.top()!=a[j]){
					vis[st.top()]--;
					st.pop();
				}
			}
		}
		while(st.size()){
			ans[st.top()]++;
			vis[st.top()]=0;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
    fclose(stdin);
    fclose(stdout);
}
