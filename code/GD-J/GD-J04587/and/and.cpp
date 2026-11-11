#include<cstdio>
#include<iostream>
using namespace std;
int n,m,ans=-1;
const int maxn=200000;
int a[maxn];
void dfs(int d,int v,int b){
	if(v<=ans){
		return;
	}
	if(d==m-1){
		ans=v;
		return;
	}
	for(int i=b+1;i<n;i++){
		dfs(d+1,a[i]&v,i);
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		dfs(0,a[i],i);
	}
	cout<<ans;
	return 0;
}
