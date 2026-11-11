#include<bits/stdc++.h>
using namespace std;
int n,m,ans=-1e9;
long long a[200005];
bool b[200005];
int check(){
	int cnt=0,sum=-1;
	for(int i=1;i<=n;i++){
		if(b[i]){
			cnt++;
			if(sum==-1)
				sum=b[i];
			else
				sum&=b[i];
		}
	}
	if(cnt!=m)
		return -1;
	return sum;
}
void dfs(int x){
	if(x>n){
		int t=check();
		if(t!=-1){
			ans=max(ans,t);
		}
		return;
	}
	b[x]=false;
	dfs(x+1);
	b[x]=true;
	dfs(x+1);
	b[x]=false;
	return;
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
