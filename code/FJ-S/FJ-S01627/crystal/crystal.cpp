#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int j=1;j<=n;j++){
		long long cnt=0,c=0,gs=0;
		for(int i=1;i<=j;i++) b[++c]=a[j]-a[i];
		sort(b+1,b+c+1);
		for(int i=1;i<=c;i++){b[i]+=b[i-1];if(b[i]>m){gs=i-1;break;}}
		ans=max(ans,gs);
	}
	cout<<ans;
	return 0;
}
