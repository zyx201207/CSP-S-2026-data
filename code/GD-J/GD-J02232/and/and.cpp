#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005];
int vis[100005];
long long k=INT_MIN;
void an(int x,int y){
	if(x<=k)return ;
	if(y==m){
		if(x>k)k=x;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			an(int(x&a[i]),y+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in",r,stdin);
	freopen("and.out",w,stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		an(a[i],1);
		vis[i]=0;
	}
	cout<<k;
	return 0;
}
