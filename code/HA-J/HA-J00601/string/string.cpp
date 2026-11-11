#include<bits/stdc++.h>
using namespace std;
int n,l,r;
long long ans=0;
const int N=2e5+5;
long long a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i]>>c[i];
	l=1,r=n;
	while (l<r){
		long long cut=min(a[r],a[l]);
		if (c[l]!=c[r]) ans+=cut;
		a[r]-=cut;
		a[l]-=cut;
		if (a[r]==0) r--;
		if (a[l]==0) l++;
	}
	cout<<ans<<endl;
	return 0;
}
