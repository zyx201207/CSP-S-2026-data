#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
int n,m,a[500005],ans[300005];
bool f[300005];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof f);
		for(int j=i;j<=n;j++)
			if(f[a[j]]) while(st.top()!=a[j]) f[st.top()]=0,st.pop();
			else f[a[j]]=1,st.push(a[j]);
		while(!st.empty()) ans[st.top()]++,st.pop();
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
