#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+5;
int n,a[MAXN];
char c[MAXN];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int l=1,r=n,ans=0;
	while(l<r){
		if(c[l]!=c[r]) ans+=min(a[l],a[r]);
		if(a[l]>a[r]) a[l]-=a[r],r--;
		else a[r]-=a[l],l++; 
	}
	cout<<ans<<endl;
	return 0;
}
