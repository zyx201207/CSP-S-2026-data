#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 1000010
int n,a[N],ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r){
		int p=min(a[l],a[r]);
		if(c[l]!=c[r]) ans+=p;
		a[l]-=p;
		a[r]-=p;
		if(!a[l]) l++;
		if(!a[r]) r--;
	}cout<<ans;
}

