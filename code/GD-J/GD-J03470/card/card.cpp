#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,b[N],a[N],ans[N];
bool vis[N];
vector<int>v; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int tot=0;
		for(int j=i;j<=n;j++) b[++tot]=a[j];
		v.clear();
		memset(vis,0,sizeof vis);
		for(int j=1;j<=tot;j++){
			if(!vis[b[j]]) v.push_back(b[j]);
			else{
				int k=v.size()-1;
				while(v[k]!=b[j]) vis[v[k]]=0,v.pop_back(),k--;
				v.pop_back(),v.push_back(b[j]);
			}
			vis[b[j]]=1;
		}
		for(int j=0;j<(int)v.size();j++) ans[v[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
} 
