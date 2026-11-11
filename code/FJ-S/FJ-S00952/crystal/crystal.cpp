#include<bits/stdc++.h>

using namespace std;

#define int long long
//y0,y1 nope
//Oct31==Dec25?
//2:33 T1
//freopen("
//play.petalwar.top
/*
998244353
Im -lyy-
luogu:lyy0918lyy 
*/

int a[500005];
int sm[500005];

signed main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+1+n);
	
	for(int i=1;i<=n;i++)
		sm[i]=sm[i-1]+a[i];
	
	int l=1,ans=0;
	
	for(int r=1;r<=n;r++){
		while((r-l+1)*a[r]-(sm[r]-sm[l-1])>m)l++;
		ans=max(ans,r-l+1);
	}
	
	cout<<ans;
	
	return 0;
}
