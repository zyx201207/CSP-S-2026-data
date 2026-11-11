#include<bits/stdc++.h> 
using namespace std;
int n,m;
int a[200005];
bool v[100005];
int ans[100005];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>5000&&m<=2){
		for(int i=1;i<=n;i++){
			ans[a[i]]++;
			if(a[i]!=a[n])ans[a[n]]++;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	if(n>5000){
		for(int i=n;i>=1;i--){
			if(ans[a[i]]==0){
				ans[a[i]]=i;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(v[a[j]]==0){
				v[a[j]]=1;
				st.push(a[j]);
			}
			else{
				while(st.top()!=a[j])v[st.top()]=0,st.pop();
			}
		}
		while(!st.empty()){
			v[st.top()]=0;
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
