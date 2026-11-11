#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN=2e5;
int n,ans;
int a[MAXN+5]; char c[MAXN+5];

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r){
		int sum=0;
		while(sum<a[l]&&l<r){
			sum+=a[r];
			if(c[l]!=c[r]) ans+=a[r];
			--r;
		}
		if(sum>a[l]){
			a[++r]=sum-a[l];
			if(c[l]!=c[r]) ans-=sum-a[l];
		}
		++l;
	}
	cout<<ans;
	return 0;
}
