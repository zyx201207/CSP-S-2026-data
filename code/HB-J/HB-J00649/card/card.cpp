#include <bits/stdc++.h>
using namespace std;
int ans[300010];
int ca[500010];
stack<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ca[i];
	}
	for(int i=1;i<=n;i++){
		bool vis[300010]={false};
		for(int j=i;j<=n;j++){
			if(vis[ca[j]]==false){
				s.push(ca[j]);
				vis[ca[j]]=true;
			}else{
				while(s.top()!=ca[j]){
					vis[s.top()]=false;
					s.pop();
				}
			}
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}

}
