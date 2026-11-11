#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,l,r;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	r=n,l=1;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++){
		long long s=0;
		s=min(a[r],a[l]);
		a[r]-=s;
		a[l]-=s;
		ans+=s*(c[r]!=c[l]);
		if(a[r]==0)r--;
		if(a[l]==0)l++;
	}
	cout<<ans;
	return 0;
}

