#include<bits/stdc++.h>
using namespace std;
const int inf=5e5+7,ans=3e5+7;
int n,m,i,j,k,l,h;
int a[inf],cnt[ans],t[ans];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			if(!t[a[j]]){
				t[a[j]]=1;
				st.push(a[j]);
			}
			else{
				while(st.top()!=a[j]){
					t[st.top()]=0;
					st.pop();
				}
				
			}
		}
		while(!st.empty()){
			cnt[st.top()]++;
			st.pop();
		}
		fill(t+1,t+1+m,0);
	}
	for(i=1;i<=m;i++) cout<<cnt[i]<<" "; 

	return 0;
}

