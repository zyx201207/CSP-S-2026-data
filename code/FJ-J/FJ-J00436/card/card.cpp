#include<iostream>
#include<stack>;
#define int long long
using namespace std;
int a[200005],ans[200005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int> s;
		int vis[200005]={0};		
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0)s.push(a[j]),vis[a[j]]=1;
			else{
				while(s.top()!=a[j])vis[s.top()]=0,s.pop();
				//vis[s.top()]=0,s.pop();
			}
			
		}
		for(int k=1;k<=m;k++)ans[k]+=vis[k];
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0; 
}
