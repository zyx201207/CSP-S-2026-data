#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000001],ans;
void dfs(long long c,long long sum,long long la){
	if(c==m){
		ans=max(ans,sum);
		return ;
	}
	for(int i=la+1;i<=n;i++){
		dfs(c+1,sum&a[i],i);
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		for(int i=1;i<=n;i++) 
			dfs(1,a[i],i);
		cout<<ans;
		return 0;
	}
	else if(m==1){
		for(int i=1;i<=n;i++) 
			ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	else if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i++)
			ans=ans&a[i];
		cout<<a;
		return  0;
	}
	else if(m==2){
		for(int i=1;i<=n;i++) 
			dfs(1,a[i],i);
		cout<<ans;
		return 0;
	} 
	return 0;
}
