#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],b[N];
int n,m,ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(b[j]) continue;
			if(a[j]&(1<<i)) cnt++;
		}
		if(cnt>=m){
			ans^=(1<<i);
			for(int j=1;j<=n;j++){
				if(b[j]) continue;
				if((a[j]&(1<<i))==0) b[j]=1;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}