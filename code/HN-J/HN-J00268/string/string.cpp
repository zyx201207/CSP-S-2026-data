#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,ans;
int a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l+1<=r){
		int minn=min(a[l],a[r]);
		if(c[l]!=c[r]){
			ans+=minn;
		}
		a[l]-=minn;
		a[r]-=minn;
		if(a[l]==0) l++;
		if(a[r]==0) r--; 
	}
	cout<<ans;
	return 0;
} 
