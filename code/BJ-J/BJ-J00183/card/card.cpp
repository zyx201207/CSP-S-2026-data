#include <bits/stdc++.h>
using namespace std;
int h[300005],a[500005];
bool w[300005];
stack<int> st;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(w[a[j]]==1){
				while(!st.empty()){
					if(st.top()!=a[j]){
						w[st.top()]=0;
						st.pop();
						
					}else{
						break;
					}
				}
			}
			else{
				st.push(a[j]);
				w[a[j]]=1;
			}
		}
		while(!st.empty()){
			h[st.top()]++;
			w[st.top()]=0;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<h[i]<<" ";
	}
	return 0;
}
