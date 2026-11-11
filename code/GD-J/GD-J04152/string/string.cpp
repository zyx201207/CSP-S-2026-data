#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],l,r,ans;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;l=1,r=n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	while(l<r){
		if(a[l]<a[r]){
			if(c[l]!=c[r]) ans+=a[l];
			a[r]-=a[l];
			l++;
		}
		else{
			if(c[l]!=c[r]) ans+=a[r];
			a[l]-=a[r];
			r--;
		}
	}
	cout<<ans;
}
