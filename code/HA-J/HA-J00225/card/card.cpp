#include<bits/stdc++.h>
using namespace std;
int a[20001];
int b[20001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		map<int,int>m;
		stack<int>st;
		for(int i=k;i<=n;i++){
			if(m[a[i]]){
				while(st.top()!=a[i]){
				    m[st.top()]=0;
					st.pop();
				}
			}else{
				st.push(a[i]);
				m[a[i]]=1;
			}
		}
		while(!st.empty()){
			b[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	
	return 0;
} 



