#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
int n,m,a[maxn],ans;
bool b[maxn];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++)if(!b[j]&&(a[j]&(1<<i)))cnt++;
		if(cnt>=m){
			for(int j=1;j<=n;j++)if((a[j]&(1<<i))==0)b[j]=1;
			ans+=(1<<i);
		}
	}
	cout<<ans;
	return 0;
}
