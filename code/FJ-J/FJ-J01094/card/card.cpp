#include <bits/stdc++.h>
using namespace std;
int n,m;
int t[300005];
int a[500005];
int ans[300005];
stack <int> st;
vector <int> g[500005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(t,0,sizeof(t));
		for(int l=i;l<=n;l++){
			if(t[a[l]]==0){
				t[a[l]]++;
				st.push(a[l]);
			}
			else{
				while(t[a[l]]!=0&&!st.empty()){
					int f=st.top();st.pop();
					if(f==a[l]){
						t[a[l]]--;	
					}
				}
				st.push(a[l]);
				t[a[l]]++;
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
