#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
bool vis[500010];
stack <int> st;
long long ans[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		fill(vis+1,vis+m+1,false);
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==false){
				st.push(a[j]);
				vis[a[j]]=true;
			}else{
				while(st.top()!=a[j]&&!st.empty()){
					vis[st.top()]=false;
					st.pop();
				}
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}
