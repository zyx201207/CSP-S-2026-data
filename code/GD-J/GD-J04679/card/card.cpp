#include<bits/stdc++.h>
using namespace std;

int a[500086];
stack<int> st;
int num[300086];
int n,m;
int ans[300086];

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	
	cin>>n>>m;
	
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}	
	
	for(int t=1;t<=n;++t){
		
		memset(num,0,sizeof(num));
		
		for(int i=t;i<=n;++i){
			if(num[a[i]]){
				while(!st.empty()&&st.top()!=a[i]){
					--num[st.top()];
					st.pop(); 
				}
			}
			else{
				st.push(a[i]);
				++num[a[i]];
			}
		}
		
		while(!st.empty()){
			++ans[st.top()];
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
