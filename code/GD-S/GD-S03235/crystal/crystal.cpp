#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+6;
int n,m,a[N],pos=1,s[N],ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		while(a[i]*(i-pos+1)-(s[i]-s[pos-1])>m){
			pos++;
		}
		ans=max(ans,i-pos+1);
	}
	cout<<ans<<'\n';
	return 0;
} 
