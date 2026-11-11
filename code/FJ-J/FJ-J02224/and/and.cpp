#include<bits/stdc++.h>
using namespace std;

int n,m,a[200010],b[200010],c[200010],ans=-1;

void dfs(int i){
	if(i>m){
		int cnt=b[1];
			
		for(int j=2;j<=m;j++)cnt&=b[j];
		ans=max(ans,cnt);
		
		return;	
	}
	for(int j=1;j<=n;j++){
		if(c[j]==1)continue;
		b[j]=a[j];
		
		c[j]=1;	
		dfs(i+1); 
		c[j]=0;
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=a[n];
	for(int i=n-1;i>=m;i--)ans&=a[i];
//	dfs(0);
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12
*/
