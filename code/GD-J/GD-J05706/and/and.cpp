#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans,mi=1e12,j;
void dfs(int x,int y,long long z){
	if(y==m){
		ans=max(ans,z);
		return;
	}
	for(;x<=n;x++){
		long long t=z;
		t&=a[x];
		dfs(x+1,y+1,t);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<mi)
			j=i;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++)
			if(i!=j)
				ans&=a[i];
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
		dfs(i+1,1,a[i]);
	cout<<ans;
	return 0; 
}
