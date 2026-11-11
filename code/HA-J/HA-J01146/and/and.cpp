#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],b[100010],ans=0;;
bool c[100010]={0};
void dfs(int step){
	if(step>m){
		int num=0;
		num=a[b[1]];
		for(int i=2;i<=m;i++){
			num=min(num,a[b[i]]);
		}
		ans=max(ans,num);
	}
	for(int i=1;i<=n;i++){
		if(c[i]==0){
			c[i]=1;
			b[step]=i;
			dfs(step+1);
			c[i]=0;
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
	dfs(1);
	cout<<ans;
	return 0;
}
