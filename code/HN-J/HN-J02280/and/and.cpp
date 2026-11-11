#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e7 + 100;
LL n,m,a[N],ans;
void dfs(LL i,LL cnt,LL x){
	if(cnt>=m||i>n){
		ans=max(ans,x);
		return;
	}
	i++;
	if(i==1){
		x=a[1]; 
		dfs(i,cnt+1,x&a[i]);
		dfs(i,cnt,a[2]);
	}
	else{
		dfs(i,cnt+1,x&a[i]);
		dfs(i,cnt,a[i]);	
	}

}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
