#include <bits/stdc++.h>
using namespace std;
long long n,a[200010],m,c[33][200010],ans,val[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	for(long long i=1;i<=n;++i){
		cin>>a[i];
		for(long long j=0;j<=30;++j){if(a[i]&(1<<j)){c[j][i]=1;}}
	}
	for(long long i=1;i<=n;++i) val[i]=1;
	for(long long i=30;i>=0;--i){
		long long cnt=0;
		for(long long j=1;j<=n;++j){if(!val[j]){continue;}if(c[i][j]){cnt++;}}
		if(cnt>=m){
			ans+=(1<<i);
			for(long long j=1;j<=n;++j){if(val[j]&&!c[i][j]){val[j]=0;}}
		}
	}
	cout<<ans;
	return 0;
}
