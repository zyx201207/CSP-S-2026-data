#include<bits/stdc++.h>
using namespace std;

bool yn[3005];
int ans[3005];
int num[200005];
stack<int> st;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
	}
	
	for(int i=1;i<=n;i++){
		for(int u=i;u<=n;u++){
			if(yn[num[u]]==false){
				st.push(num[u]);
				yn[num[u]]=true;
			}else{
				while(st.top()!=num[u]){
					yn[st.top()]=false;
					st.pop();
				}
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			yn[st.top()]=false;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
} 
