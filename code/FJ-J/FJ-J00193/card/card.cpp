#include<bits/stdc++.h>
using namespace std;
stack<int> sta,st;
int n,m,a[500005],b[300005][2];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		while(!sta.empty()) sta.pop();
		while(!st.empty()) st.pop();
		for(int j=i;i<=n;i++){
			int l=1;
			while(!sta.empty()){
				if(sta.top()==a[j]){
					while(!st.empty()) st.pop();
					l=0;
					break;
				}
				st.push(sta.top());
				sta.pop();
			}
			if(l==1){
				while(!st.empty()){
					sta.push(st.top());
					st.pop();
				}
				sta.push(a[j]);
			}
		}
		while(!st.empty()){
			sta.push(st.top());
			st.pop();
		}
		while(!sta.empty()){
			if(b[sta.top()][1]==1){
				b[sta.top()][0]++;
				b[sta.top()][1]=0;
			}
			sta.pop();
		}
		for(int i=1;i<=m;i++) b[i][1]=1;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i][0]<<" ";
	}
	
	return 0;
}
