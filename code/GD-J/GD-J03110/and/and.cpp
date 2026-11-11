#include<iostream>
#include<cmath>
using namespace std;
//int INT_MAX=2147483647; 
int h=INT_MAX;
const int N=2e5;
int n,m;
int a[N];
long long test=1;
bool dis[N];
int ans=INT_MIN;
void dfs(int k,int sum){
	if(k>m){//已经选完k个了 
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!dis[i]){//没有选过 
			dis[i]=true;
			dfs(k+1,(sum & a[i]));
			dis[i]=false;
		}
	}
}
void over(){
	if(m==1){//只用选最大值 
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
//		cout<<ans;
	}
	if(m==n){//全部一起按位与 
		ans=h;
		for(int i=1;i<=n;i++){
			ans=(ans & a[i]);
		}
//		cout<<ans;
	}
	if(m==2){//暴力枚举选两个 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ans=max(ans,(a[i] & a[j]));
				}
			}
		}
//		cout<<ans;
	}
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	over();
	dfs(1,h);
	cout<<ans;
}
int main(){
	freopen("ans.in","r",stdin);
	freopen("ans.out","w",stdout);
	solve();
	return 0;
}

