#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,a[N],ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		int t=min(a[l],a[r]);
		a[l]-=t,a[r]-=t;
		if(c[l]!=c[r])
		ans+=t;
		if(!a[l])l++;
		if(!a[r])r--;	
	}
	cout<<ans;
	return 0;
}
