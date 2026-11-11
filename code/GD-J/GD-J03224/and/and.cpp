#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e5+5;
int n,m,ans,a[N];
bool chk(int x){
	int cnt=0;
	for(int i=1;i<=n;i++)
		cnt+=(a[i]&x)==x;
	return cnt>=m;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=29;~i;i--)
		if(chk(ans|1<<i))ans|=1<<i;
	cout<<ans;
	return 0;
}
