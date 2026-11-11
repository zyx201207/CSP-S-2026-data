#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+3;
int n,m;
int g[N],ans[N];
bool used[N];
stack<int> st;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>g[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			//cout<<j;
			//cout<<" round:"<<i<<" read:"<<used[g[j]]<<" "<<g[j];
			if(used[g[j]]){
				//cout<<"while"<<endl;
				while(st.top()!=g[j]){
					used[st.top()]=0;st.pop();
				}
				st.pop();
			}else{
				used[g[j]]=1;
			}
			st.push(g[j]);
			
			//cout<<" top:"<<st.top()<<endl;
		}
		while(!st.empty()){
			//cout<<st.top()<<endl;
			ans[st.top()]++;
			st.pop();
		}
		for(int i=0;i<n;i++){
			used[i]=0;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
