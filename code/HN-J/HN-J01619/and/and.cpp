#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int n,m,a[N],v[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		v[i]=1;
	}
	int ans=0;
	for(int i=30;i>=0;--i){
		int cnt=0;
		for(int j=1;j<=n;++j){
			if(v[j]&&((a[j]>>i)&1))++cnt;
		}
		if(cnt>=m){
			ans|=(1ll<<i);
			for(int j=1;j<=n;++j){
				if(v[j]&&((a[j]>>i)&1));
				else v[j]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}

