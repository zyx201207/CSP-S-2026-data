#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int a[200005],ans[200005],maxn=0,b[200005];
int n,m;
bool vis[200005];
void search(int k){
	if(k>m){
		int res=ans[1];
		for(int i=2;i<=m;i++){
			res=res&ans[i];
		}
		maxn=max(maxn,res);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]&&i>k-1){
			vis[i]=true;
			ans[k]=a[i];
			search(k+1);
			vis[i]=false;
		}
	}
}
bool check(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<30;j++){
			if(a[i]!=pow(2,j)-1) return false;
		}
	}
	return true;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxi=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxi=max(maxi,a[i]);
	}
	if(m==1){
		cout<<maxi;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		int maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}
	if(check()){
		for(int i=1;i<=n;i++) b[i]=a[i];
		sort(b+1,b+n+1,cmp);
		cout<<b[m];
	}
	else{
		search(1);
		cout<<maxn;
		return 0;
	}
	return 0;
}
