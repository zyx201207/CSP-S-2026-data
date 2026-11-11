#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans[N];
bool vis[N];
stack<int> z;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(vis,false,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]) vis[a[j]]=true,z.push(a[j]);
			else{
				while(z.size()>0){
					if(z.top()==a[j]) break;
					z.pop();
				}
			}
		}
		while(z.size()>0){ans[z.top()]++;z.pop();}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
} 
