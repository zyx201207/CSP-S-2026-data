#include<iostream>
#include<vector>
#define int long long 
using namespace std;
int n,m,a[200005],cnt,ans;
bool vis[200005];
signed main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i =1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i =30;i>=0;i--){
		cnt = 0;
		for(int j =1;j<=n;j++){
			if(vis[j])continue;
			if(a[j]&(1ll<<i)){
				++cnt;
			}
		}
		if(cnt>=m){
			ans += (1ll<<i);
			for(int j =1;j<=n;j++){
				if((a[j]&(1ll<<i))||vis[j])continue;
				vis[j] = 1;
			}
		}
	}
	cout<<ans;
} 
/*
4 2
3 15 12 12


5 3
31 3 1 15 7

*/
