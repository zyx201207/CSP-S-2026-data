#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5;
const int MAXM = 2e5;
int card[MAXN];
int bucket[MAXM];
bool vis[MAXM];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n;
	int m;
	cin>>n>>m;
	for(int i = 0;i < n;i++){
		cin>>card[i];
	}
	for(int i = 0;i < n;i++){
		memset(vis,false,sizeof(vis));
		 for(int j = i;j < n;j++){
			  if(vis[card[j]]){
				  while(st.top() != card[j]){
					  vis[st.top()] = false;
					  st.pop();
				  }
			  }
			  else{
				  st.push(card[j]);
				  vis[card[j]] = true;
			  }
		  }
		  while(!st.empty()){
			  bucket[st.top()]++;
			  st.pop();
		  }
	  }
	  for(int i = 1;i <= m;i++){
		  cout<<bucket[i]<<" ";
	  }
	  return 0;
}