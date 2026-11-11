#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[300005];
bool pos[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	stack<int> st;
    int n,m;
    cin>>n>>m;
    int s;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			st.push(a[j]);
			if(j>i&&pos[a[j]]){
				s=st.top();
				st.pop();
				while(!st.empty()&&st.top()!=s){
					pos[st.top()]=0;
					st.pop();
				}
			}
			pos[a[j]]=1;
		}
		while(!st.empty()){
			ans[st.top()]++;
			pos[st.top()]=0;
			st.pop();
		}
		
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
