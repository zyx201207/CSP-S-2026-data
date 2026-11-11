#include<bits/stdc++.h>
using namespace std;
#define int long long
int m,n;
int mxx,t;
int a[200005];
void dfs(int i,int c,int ans){
	if(c==m){
		mxx=max(mxx,ans);
		return ;
	}
	if(i>=n)return ;
	dfs(i+1,c,ans);
	dfs(i+1,c+1,ans&a[i+1]);
	
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("add.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	if(m==1){
		int mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
		return 0;
	}
	if(m==2){
		int mx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==n){
		int mx=a[1];
		for(int i=2;i<=n;i++){
			mx=mx&a[i];
		} 
		cout<<mx;
		return 0;
	}
	for(int i=1;i<=n-m+1;i++){
		dfs(i,1,a[i]);
	}
	cout<<mxx;
	return 0;
}
