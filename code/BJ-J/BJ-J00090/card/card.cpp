#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],ans[500010],vis[500010];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack <int> s;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(s.top()!=a[j]){
					int t=s.top();
					s.pop();
					vis[t]=0;
				}
			}
			else{
			    vis[a[j]]=1;
			    s.push(a[j]);
			}
		}
		while(!s.empty()){
			int q=s.top();
			ans[q]++;
			vis[q]=0;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
