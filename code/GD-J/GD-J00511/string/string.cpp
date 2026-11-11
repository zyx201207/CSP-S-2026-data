#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n;
ll ans=0;
int sum[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>sum[i]>>c[i];
	int l=1,r=n;
	while (l<r){
		int t=min(sum[l],sum[r]);
		sum[l]-=t;sum[r]-=t;
		if (c[l]!=c[r]) ans+=t;
		if (sum[l]==0) l++;
		if (sum[r]==0) r--;
	}
	cout<<ans;
	return 0;
}
