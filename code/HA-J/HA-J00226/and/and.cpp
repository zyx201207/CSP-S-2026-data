#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+100;
int n,m,a[N],ans;
bool v[N];
void dfs(int x,int cnt){
	if(x==m){
		ans=max(ans,cnt);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			dfs(x+1,cnt&a[i]);
			v[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	 cin>>n>>m;
	 for(int i=1;i<=n;i++){
	 	cin>>a[i];
	 }
	 for(int i=1;i<=n;i++){
	 	v[i]=1;
	 	dfs(1,a[i]);
	 	v[i]=0;
	 }
	 cout<<ans;
	return 0;
}
