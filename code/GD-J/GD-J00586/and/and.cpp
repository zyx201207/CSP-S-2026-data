#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int n,m;
bool cmp(int l,int r){
	return l>r;
}
int vis[N];
int anss=-1;
void dfs(int pos,int sheng,int ands){
	if(vis[pos]||sheng==0)return;
	vis[pos]=1;
	anss=max((ands&a[pos]),anss);
	dfs(pos+1,sheng--,anss);
	dfs(pos+1,sheng,ands);
}
int main(){
	freopen("and2.in","r",stdin);
	freopen("and2.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	if(m==2){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			if(a[i]!=ans){
				ans=(ans&a[i]);
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	else{
		dfs(1,m,-1);
		cout<<anss;
	}
	return 0;
} 

