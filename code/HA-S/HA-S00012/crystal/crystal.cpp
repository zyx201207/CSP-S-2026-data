#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
int n,m,a[N],ans=1,cnt,pos;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		cnt+=(a[i]-a[i-1])*(i-1);
		if(cnt>m){
			cout<<a[i-1]<<"\n";
			break;
		}
		ans++;
	}
	cout<<ans;
	return 0;
}
