#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N];
bool vis[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int tot=0,t=0;
	for(int i=29;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(vis[j]) continue;
			if((a[j]>>i)&1) cnt++;
		}
		if(cnt>=m){
			t+=(1<<i);
			for(int j=1;j<=n;j++){
				if(vis[j]) continue;
				if(!((a[j]>>i)&1)) vis[j]=true;
			}
		}
	}
	cout<<t<<"\n";
	return 0;
}
