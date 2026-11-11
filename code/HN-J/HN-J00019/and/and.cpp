#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005],vis[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0,flag=0;
	for(int k = 31;k>=0;k--){
		int sum=0;
		for(int i = 1;i<=n;i++){
			if(vis[i]==0){
				if(((a[i]>>k)&1ll)==1){
					sum++;
				}
			}
		}
		if(sum>=m){
			ans+=(1ll<<k);
			for(int i = 1;i<=n;i++){
				if(((a[i]>>k)&1ll)==0){
					vis[i]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
二进制位贪心（ 
不知z1s2y3会做吗
m=1是输出最大吗 
*/
