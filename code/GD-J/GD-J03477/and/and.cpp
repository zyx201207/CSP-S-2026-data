#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m;
int a[N];
bool b[N];
int ans=0;
void dfs(int x,int d){
	if(d==m){ans=max(ans,x); return ;}
	for(int i=1;i<=n;i++){
		
		if(b[i]==1) continue;
		b[i]=1;
		if(x==-1) dfs(a[i],d+1);
		else dfs(x&a[i],d+1);
		b[i]=0;
	}
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;

	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	dfs(-1,0);
	cout<<ans; 
	return 0;
} 
