#include<bits/stdc++.h>
#define int long long
using namespace std;
int l,r,n,a[200005],s;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	l=1,r=n;
	while(l<r){
		while(l<r){
			s+=(c[l]!=c[r])*min(a[l],a[r]);
			if(a[r]>=a[l]){
				a[r]-=a[l];
				break;
			}
			a[l]-=a[r--];
		}
		l++;
	}
	cout<<s;
	return 0;
}
