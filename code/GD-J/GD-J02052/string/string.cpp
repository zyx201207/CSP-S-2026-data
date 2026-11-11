#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r){
		int m=min(a[l],a[r]);
		if(c[l]!=c[r]) ans+=m;
		a[l]-=m;
		a[r]-=m;
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<ans;
	return 0;
}
