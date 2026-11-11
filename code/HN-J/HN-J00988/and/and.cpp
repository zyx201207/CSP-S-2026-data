#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m;
int ans;
int a[N];
bool vis[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[i]=1;
	}
	int ans=0;
	for(int k=30;k>=0;k--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(((a[i]>>k)&1)&&vis[i]){
				cnt++;
			}
		}
		if(cnt>=m){
			ans+=(1<<k); 
			for(int i=1;i<=n;i++){
				if(!((a[i]>>k)&1)){
					vis[i]=0;
				}
			}
		} 
	}
	cout<<ans;
	return 0; 
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
