#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],num[300005],b[300005];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]==1){
				while(st.top()!=a[j]){
					b[st.top()]=0;
					st.pop();
				}
			}else st.push(a[j]);
			b[a[j]]=1;
		}
		while(!st.empty()){
			b[st.top()]=0;
			num[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<' ';
	}
	return 0;
} 
