#include<bits/stdc++.h>
using namespace std;

long long n,m,num[200010],a[200010];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		bool vis[200010]={};
		stack<long long>st;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==1){
				while(st.top()!=a[j]){
					vis[st.top()]=0;
					st.pop();
				}
				st.pop();
			}
			st.push(a[j]);
			vis[a[j]]=1;
		}
		for(int j=1;j<=m;j++)num[j]+=vis[j];
	}
	for(int i=1;i<=m;i++)cout<<num[i]<<' ';
}
