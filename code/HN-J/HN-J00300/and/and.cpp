#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool use[200005];
int n,m,mx=-1;
void dfs(int pos){
	if(pos>n){
		int cnt=0;
		int sum=INT_MAX;
		for(int i=1;i<=n;i++)
			if(use[i]){
				sum=sum&a[i];
				cnt++;
			}
		if(cnt==m)
			mx=max(mx,sum);
		return;
	}
	use[pos]=1;
	dfs(pos+1);
	use[pos]=0;
	dfs(pos+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1);
	cout<<mx;
	return 0;
}
