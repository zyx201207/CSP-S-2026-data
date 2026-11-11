#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,q[500100],h,t;
long long a[500100],ans,anss;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	h=1;t=0;
	for(int i=1;i<=n;i++){
		ans+=(a[i]-a[i-1])*(t-h+1);
		while(h<=t&&ans>m){
			ans-=(a[i]-a[q[h]]);
			h++;
		}
		q[++t]=i;anss=max(anss,t-h+1);
	}
	cout<<anss<<"\n";
}