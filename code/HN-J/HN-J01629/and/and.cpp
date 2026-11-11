#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,a[N],da,pf[30];
int dfs(int x,int gs,int dq){
	if(gs>=m) return dq;
	if(x>n) return 0;
	if(gs==0) return max(dfs(x+1,gs+1,a[x]),dfs(x+1,gs,dq));
	return max(dfs(x+1,gs+1,dq & a[x]),dfs(x+1,gs,dq));
}
int cz(int x){
	for(int i=1;i<=20;i++){
		if(pf[i-1]<=x&&x<pf[i]) return pf[i];
	}
} 
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	pf[0]=1;
	for(int i=1;i<=30;i++) pf[i]=pf[i-1]*2;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20) da=max(dfs(1,1,a[1]),dfs(1,0,0));
	else if(n<=2000){
		if(m==1) for(int i=1;i<=n;i++) da=max(da,a[i]);
		else if(m==2) for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) da=max(da,a[i] & a[j]);
		else{
			da=a[1];
			for(int i=2;i<=n;i++) da=da & a[i];
		}
	}
	cout<<da;
	return 0;
}
