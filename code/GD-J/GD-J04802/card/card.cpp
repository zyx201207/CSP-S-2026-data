#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+3;
int a[N],n,m,ans[N];
bool instack[N];
stack<int> st;//100+80+85+24=289.
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			if (instack[a[j]]){
				while (st.top()!=a[j]){
					int t=st.top();
					instack[t]=0;
					st.pop();
				}
				st.pop();
			}
			st.push(a[j]);
			instack[a[j]]=1;
			//print_sta();
		}
		while (!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
		memset(instack,0,sizeof instack);
	}
	for (int i=1;i<=m;i++) cout<<ans[i]<<' ';
}//aabbc
