#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,m,b[N],ans[N];
int c[N];
string s;
stack<int>st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int i=1;i<=m;i++) b[i]=0;
		for(int j=i;j<=n;j++){
			if(b[c[j]]){
				while(1){
					b[st.top()]=0;
					if(st.top()==c[j]){
						st.pop();
						break;
					}
					st.pop();
				}
			}
			st.push(c[j]);
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
