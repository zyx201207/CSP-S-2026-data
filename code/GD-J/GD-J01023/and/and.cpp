#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200020],ans;
bool used[200020];
void dfs(int t,long long now,int cnt){
	if(t==0){
		ans=max(ans,now);
		return;
	}
	for(int i=cnt;i<n;i++){
		if(t==m){
			now=a[i];
			used[i]=true;
			dfs(t-1,now,cnt+1);
			used[i]=false;
		}
		else{
			if(used[i]==false){
				used[i]=true;
				dfs(t-1,now&a[i],cnt+1);
				used[i]=false;
			}
		}	
	}
	return;
}
int main(){
	freopen("and .in","r",stdin) ;
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(m,1,0);
	cout<<ans;
	return 0;
}
