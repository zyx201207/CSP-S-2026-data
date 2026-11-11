#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans;
bool vis[200010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=29;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if((a[j]&(1<<i))&&!vis[j]) cnt++;
		}
		if(cnt>=m){
			ans+=(1<<i);
			for(int j=1;j<=n;j++){
				if(!(a[j]&(1<<i))) vis[j]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
