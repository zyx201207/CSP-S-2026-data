#include<bits/stdc++.h>
#define ll long long
using namespace std;
int l=1,r;
ll ls=1,rs,midl,midr,m;
int n;
ll a[200050];
char c[200050];
ll ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		rs+=a[i];
	}
	r=n;
	if(n%2==1) midl=midr=rs/2+1;
	else midl=rs/2;midr=midl+1;
	while(ls<=midl&&rs>=midr){
		m=min(a[l],a[r]);
		a[l]-=m;a[r]-=m;ls+=m;rs-=m;
		if(c[l]!=c[r]){	
			ans+=m;
		}
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<ans;
	return 0;
}
