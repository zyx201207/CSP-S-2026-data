#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[200010];
int mx=-1e9;
int s[200010],tong[200010];
void dfs(int u,int sp,int su){
	if(u>n){
		if(su>k)mx=max(mx,sp);
		return ;
	}
	else{
		dfs(u+1,sp,su);
		if(sp==-1)dfs(u+1,a[u],su+1);
		else dfs(u+1,sp&a[u],su+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(k==1){
		cout<<a[n]<<endl;
		return 0;
	}
	if(k==2){
		int y=a[n]&a[n-1];
		for(int i=n;i>=1;i--){
			int x=a[i]&a[i-1];
			if(x<y){
				cout<<y<<endl;
				break;
			}
			else y=x;
		}
		return 0;
	}
	if(k==n){
		int s=a[1];
		for(int i=2;i<=n;i++){
			s=s&a[i];
		}
		cout<<s<<endl;
		return 0;
	}
	if(k==n-1){
		int s=a[1];
		for(int i=2;i<=n-1;i++){
			s=s&a[i];
		}
		cout<<s<<endl;
		return 0;
	}
	dfs(1,-1,1);
	cout<<mx<<endl;
	return 0;
}
