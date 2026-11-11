#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int n,m,a[200010],MAX,ans,back;
void dfs(int deep,int can){
	if(deep==m){
		MAX=max(MAX,ans);
//		ans=back;
		return;
	}
	for(int i=can+1;i<=n;i++){
		if(deep==1)ans=a[i];
		back=ans;
		ans=ans&a[i];
		dfs(deep+1,i);
	}
//	ans=back;
	return;
}
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,1);
	cout<<MAX;
	return 0;
}
