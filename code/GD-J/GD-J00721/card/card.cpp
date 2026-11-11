#include<bits/stdc++.h>
using namespace std;
long long lst[3005],a[500005],cnt[3005];
stack<int>st;
bool vis[3005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		memset(lst,-1,sizeof lst);
		long long ans=0,tmp=0;
		for(int j=i;j<=n;j++){
			if(lst[a[j]]==-1){
				st.push(a[j]);
				lst[a[j]]=j;
			}else{
				if(!vis[lst[a[j]]]){
					for(int k=lst[a[j]];k<j&&!st.empty();k++){
						st.pop();
						vis[k]=1;
					}
					lst[a[j]]=j;
				}
				st.push(a[j]);
			}
		}
		while(!st.empty()){
			if(!vis[st.top()]){
				cnt[st.top()]++;
				vis[st.top()]=1;
			}
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
}
