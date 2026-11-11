#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,a[100005],ans=0;
void dfs(int num,int step,int last){
	if(step==m){
		ans=max(ans,num);
	}
	for(int i=last+1;i<n;i++){
		dfs(num&a[i],step+1,i);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		dfs(a[i],1,i);
	}
	
	cout<<ans;
	
}

