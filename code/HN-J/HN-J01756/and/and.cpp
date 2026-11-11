#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m,k,ans,maxx,b[200005];
vector<int> v;
void dfs(int x){
	if(x==m+1){
		maxx=k;
		for(auto it:v)
			maxx&=it;
		ans=max(maxx,ans);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			k=a[i];
			b[i]=1;
			v.push_back(a[i]);
			dfs(x+1);
			b[i]=0;
			v.pop_back();
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
} 
