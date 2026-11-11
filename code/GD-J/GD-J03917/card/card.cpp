#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N],vis[M],ans[M]; 
stack<int> st;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(st.top()!=a[j])
					vis[st.top()]=0,
					st.pop();
			}
			else
				st.push(a[j]),
				vis[a[j]]=1;
		}
		while(!st.empty())
			ans[st.top()]++,
			vis[st.top()]=0,
			st.pop();
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
