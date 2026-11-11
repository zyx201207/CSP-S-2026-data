#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,ans,a[N],vis[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=30;j>=0;j--){
		int num=0;
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			int x=a[i];
			if((x>>j)&1)num++;
		}
		if(num>=m){
			ans+=(1<<j);
			for(int i=1;i<=n;i++){
				int x=a[i];
				if((x>>j)&1){
					continue;
				}
				vis[i]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
//Trick||Treat!
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
