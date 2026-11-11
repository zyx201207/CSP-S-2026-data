#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,a[N],l=1,r,ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	while(l<=r){
		int ab=min(a[l],a[r]);
		a[l]-=ab,a[r]-=ab;
		if(c[l]!=c[r]) ans+=ab;
		if(a[l]==0) l++;
		else r--;
	} 
	cout<<ans;
	return 0;
} 
