#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,k,a[200005];
bool cmp(int a,int b){
	return (a&k)>(b&k);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(k=(1ll<<29);k;k>>=1){
		sort(a+1,a+1+n,cmp);
		int id=n;
		for(int i=1;i<=n;i++){
			if((a[i]&k)==0){
				id=i-1;
				break;
			}
		}
		if(id>=m) ans+=k,n=id;
	}
	cout<<ans;
	return 0;
}

