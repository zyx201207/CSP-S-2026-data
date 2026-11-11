#include<bits/stdc++.h>
using namespace std;
stack<int> st;
int n,m;
int t[300005],a[500005],s[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			if(t[a[i]]==0){
				st.push(a[i]);
				t[a[i]]=1;
			}else{
				while(st.top()!=a[i]&&st.size()){
					t[st.top()]=0;
					st.pop();
				}
			}
		}
		while(!st.empty()){
			s[st.top()]++;
			st.pop();
		}
		for(int i=1;i<=m;i++){
			t[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
