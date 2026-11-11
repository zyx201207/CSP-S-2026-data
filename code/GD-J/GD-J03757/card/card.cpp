#include<bits/stdc++.h>
using namespace std;
int n,m,a[5000005],ans[5000005];
bool f[5000005];
stack<int>st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
//		memset(f,false,sizeof(f));
		for(int j=i;j<=n;j++){
			if(f[a[j]]==0)st.push(a[j]),f[a[j]]=1;
			else if(f[a[j]]==1){
				f[a[j]]=0;
				while(st.top()!=a[j]){
					st.pop();
				}
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			f[st.top()]=0;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
} 
