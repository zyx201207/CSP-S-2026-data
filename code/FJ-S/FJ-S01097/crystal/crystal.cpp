#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n;
ll m,ans=0,v=0,
	a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1,j=1;i<=n;++i){
		while((0ll+i-j)*a[i]-v>m){
			v-=a[j];
			j++;
		}
		ans=max(ans,1ll+i-j);
		v+=a[i];
	}
	cout<<ans;
	return 0;
}
