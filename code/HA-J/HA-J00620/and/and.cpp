#include<bits/stdc++.h>
using namespace std;
int n,m;
long long mmax=0;
bool vis[210000];
int a[210000];
void dfs(int now,long long cnt){
	if(now==m){
		mmax=max(mmax,cnt);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if((cnt&a[i])>=cnt){
				dfs(now+1,(cnt&a[i]));
			}
			vis[i]=0;
		}
	}
	return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(1,a[i]);
		vis[i]=0;
	}
	cout<<mmax;
    return 0;
}
