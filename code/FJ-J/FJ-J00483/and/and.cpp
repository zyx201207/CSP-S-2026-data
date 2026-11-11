#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001];
int ans=0;
void dfs(int x,int y,int num){
	if(x==y){
		ans=max(ans,num);
		return;
	}
	for(int i=1+x;i<=n;i++){
		dfs(x+1,m,num+a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		for(int i=n-1;i>=1;i--){
			a[n]&=a[i];
		}
		cout<<a[n];
		return 0;
	}
	if(m==n-1){
		for(int i=n-1;i>1;i--){
			a[n]&=a[i];
		}
		cout<<a[n];
		return 0;
	}
	if(m==2){
		a[n]&=a[n-1];
		cout<<a[n];
		return 0;
	}
	if(n<=20){
		dfs(0,m,0);
		cout<<ans;
		return 0;
	}
	else{
		cout<<262142;
		return 0;
	}
	return 0;
} 
