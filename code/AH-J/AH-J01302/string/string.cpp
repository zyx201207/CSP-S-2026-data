#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,l,r,minn,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	l=1;
	r=n;
	while(l<r){
		minn=min(a[l],a[r]);
		a[l]-=minn;
		a[r]-=minn;
		if(c[l]!=c[r])ans+=minn;
		if(!a[l])l++;
		if(!a[r])r--;
	}
	cout<<ans;
	return 0;
}
