#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],num[N],instack[N];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			instack[j]=0;
		for(int j=i;j<=n;j++){
			if(!instack[a[j]])
				instack[a[j]]=1,st.push(a[j]);
			else{
				while(st.top()!=a[j])
					instack[st.top()]=0,st.pop();
			}
		}
		while(!st.empty()){
			num[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)
		cout<<num[i]<<" ";
	return 0;
}
