#include <bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);cout.tie(0);
	long long n,cnt=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
	cin>>a[i]>>c[i];
	cnt+=a[i];
	}
	long long l=1,r=n;
	long long cntt=0;
	long long ans=0;
	while(l<r){
		cntt=min(a[l],a[r]);
		if(c[r]!=c[l])ans+=cntt;
		a[l]-=cntt;
		a[r]-=cntt;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
		if(l==r)break;
	}
	cout<<ans<<'\n';
	
} 
