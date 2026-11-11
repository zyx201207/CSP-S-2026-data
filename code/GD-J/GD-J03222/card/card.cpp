#include<bits/stdc++.h>
using namespace std;
int n,m,ans[300010],a[500010],sum=0,nxt[300010];
vector<int>f[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	f[n].push_back(n);nxt[a[n]]=n;
	for(int i=n-1;i>0;i--){
		if(nxt[a[i]]){
			f[i]=f[nxt[a[i]]];
		}
		else{
			f[i]=f[i+1];
			f[i].push_back(i);
			nxt[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j:f[i])ans[a[j]]++;
	
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	
	return 0;
} 
