#include<bits/stdc++.h>
using namespace std;
stack<int> st;
int t[500086],ans[500086],v[500086];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",v+i);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!t[v[j]]){
				t[v[j]]++;
				st.push(v[j]);
			}else{
				while(1){
					if(st.top()==v[j]) break;
					t[st.top()]--;
					st.pop();
				}
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			t[st.top()]--;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
