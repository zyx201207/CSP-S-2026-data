#include<bits/stdc++.h>
using namespace std;
int n;
int m;
bool f[300010];
long long a[500010];
long long ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int i=1;i<=m;i++){
			f[i]=0;
		}
		stack<long long> st;
		for(int j=i;j<=n;j++){
			if(f[a[j]]){
				while(st.top()!=a[j]){
					f[st.top()]=0;
					st.pop(); 
				} 
			}else{
				f[a[j]]=1;
				st.push(a[j]);
			}
			
		}
		while(!st.empty()){
			ans[st.top()]++;//cout<<ans[st.top()];
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
