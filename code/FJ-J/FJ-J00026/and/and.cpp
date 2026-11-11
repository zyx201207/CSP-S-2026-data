#include<bits/stdc++.h>
using namespace std;
int a[200001] ,n,m,h[200005],ans;
void dfs(int i , int len){
	if(len == n){
		ans = max(ans,i);
		return;
	}
	for(int j = 1 ; j <= n ; j++){
		if(!h[i]){
			h[j] = 1;
			dfs(i&a[j],len+1);
			h[j] = 0;
		}
	}
	return;
}
int main(){
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m == n){
		ans=a[1];
		for(int i = 2; i<=n;i++)
			ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	if((a[1]==(1<<a[1])/2-1)&&(a[2]==(1<<a[2])/2-1)){
		cout<< a[n-m+1];
		return 0;
	}
	for(int i = 1 ; i<= n;i++){
		h[i]=1;
		dfs(a[i],1);
		h[i]=0;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
