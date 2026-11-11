#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,ans,y,s=1,a[N];
int b[N],pos,minn=LLONG_MAX,cnt;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]==i) cnt++;
	}
	y=a[2]-a[1];
	bool fl=1;
	for(int i=2; i<n; i++) {
		if(a[i+1]-a[i]!=y) {
			fl=0;
			break;
		}
	}
	if(fl) {
		m/=y;
		for(int i=n; i>=1; i--) {
			if((i-1)*i/2<=m) {
				cout<<i<<endl;
				return 0;
			}
		}
	} else if(cnt==n) {
		for(int i=n; i>=1; i--) {
			if((i-1)*i/2<=m) {
				cout<<i<<endl;
				return 0;
			}
		}
	} else {
		sort(a+1,a+1+n);
		for(int i=1; i<n; i++) {
			b[i]=a[i+1]-a[i];
			if(b[i]<minn&&b[i]!=0) {
				minn=b[i];
				pos=i;
			}
		}
		for(int i=pos; i<n; i++) {
			if(i==pos) {
				m-=b[i];
			} else {
				m-=b[i]*s;
				s++;
			}
			if(m<=0) break;
		}
		cout<<s;
	}
	return 0;
}
