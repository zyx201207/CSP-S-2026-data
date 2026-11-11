#include<bits/stdc++.h>
using namespace std;
int n,m,maxn=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	vector<int> ans(m+1,0),a(n+1),b(m+1,0);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>0;i--){
		if(b[a[i]]!=0) maxn=max(b[a[i]],maxn);
		else b[a[i]]=i;
		vector<bool> sc(m+1,false);
		for(int j=max(maxn,i);j<=n;j++) if(!sc[a[j]]) ans[a[j]]++,sc[a[j]]=true;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
} 
