#include<bits/stdc++.h>
#define ll long long
#define N 200005

using namespace std;
int n,k,a[N];
int dfs(int dep,int ct,int num){
	if(ct==0){
		return num;
	}
	int mx=0;
	for(int i=dep+1;i<=n;i++){
		if(a[i]==0){
			continue;
		} 
		int x;
		if(ct==k){
			x=dfs(i,ct-1,a[i]);
		}
		else{
			x=dfs(i,ct-1,(num & a[i]));
		}
		mx=max(x,mx);
	}
	return mx;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<dfs(0,k,0);
	return 0;
}
