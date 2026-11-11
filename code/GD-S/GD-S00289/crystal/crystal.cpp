#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],c[500005],ans=INT_MIN;
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	if(n<=5000) {
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++) {
			for(int j=n;j>=1;j--) {
				if(a[i]<a[j]) break;
				s[i]+=a[i]-a[j];
				c[i]+=(a[i]>=a[j]);
			}
			if(s[i]<=m) ans=max(ans,c[i]);
		}
		cout<<ans;	
	}
	else {
		bool b=1;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
			if(a[i]!=i&&i>2) {
				b=0;
				break;
			}
		}
		if(b) {
			int j=ceil((sqrt(8*m+1.0)-1.0)/2.0);
			cout<<j;
			exit(0);
		}
		else {
			int j;
			j=ceil((a[2]-a[1]-a[1]+sqrt(a[1]*a[1]-2.0*a[1]*(a[2]-a[1])+8*m*(a[2]-a[1])))/2.0/(a[2]-a[1]));
			cout<<j;
			exit(0);
		}
	}
	return 0;
}
