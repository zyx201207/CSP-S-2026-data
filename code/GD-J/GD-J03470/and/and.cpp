#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans;
bool vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	for(int i=29;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++) if((a[j]>>i)&1) cnt++; 
		if(cnt>=m){
			cnt=0;
			for(int j=1;j<=n;j++){
				if((a[j]>>i)&1) cnt++,vis[j]=1;
				if(cnt==m) break;
			}
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]&&!ans) ans=a[i];
		else if(vis[i]) ans&=a[i];
	}
	cout<<ans;
	return 0;
} 
