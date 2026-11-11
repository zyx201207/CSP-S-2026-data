#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;ll a[200005];
ll maxn=-1,ans;
void dfs(int deep,int num){
	if(deep>=m){
		maxn=max(maxn,ans);
		return;
	}
	for(int i=num+1;i<=n;i++){
		ll sum=ans;
		ans&=a[i];
		dfs(deep+1,i);
		ans=sum;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m+1;i++){
		ans=a[i];
		dfs(1,i);
	}
	cout<<maxn<<"\n";
	return 0;
} 
