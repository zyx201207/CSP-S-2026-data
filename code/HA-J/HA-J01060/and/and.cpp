#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int a[N];
bool flag[N];
int n,m;
int ans=-1;
void dfs(int id,int step,int cnt){
	if(id==m+1){
		ans=max(ans,cnt);
		return ;
	}
	if(cnt==0){
		cnt=a[step];
	}
	for(int i=step+1;i<=n;i++){
		if(!flag[i]){
			flag[i]=1;
			dfs(id+1,i,a[i]&cnt);
			flag[i]=0;
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
	dfs(1,0,0);
	cout<<ans;
	return 0;
}