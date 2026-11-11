#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500005],vis[500005];
int ans[300005];
stack<int>s;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			if(vis[a[i]]==0){
				vis[a[i]]=1;
				s.push(a[i]);
			}
			else{
				while(!s.empty()){
					if(s.top()==a[i]){
						break;
					}
					vis[s.top()]=0;
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
	return 0;
}
