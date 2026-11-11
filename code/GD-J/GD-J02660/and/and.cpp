#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],l,r,m,ri,b[200001],ans=0;
char c[200005];
int dfs(int f,int v){
	int ans=0,x,y;
	if(f>m) return v;
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			if(f==1) y=a[i];
			else y=v&a[i];
			ans=max(ans,dfs(f+1,y));
			b[i]=0;
		}
	}
	return ans;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ans=dfs(1,0);
	cout<<ans;
	return 0;
}
