#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],ans=0;
void dfs(int step,int sum,int h){
	if(step==m){
		ans=max(ans,sum);
//		cout<<sum<<" ";
		return;
	}
	for(int i=1;i<=n;i++){
		if(i>h){
			dfs(step+1,sum&a[i],i);
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
	dfs(0,(1<<31)-1,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

