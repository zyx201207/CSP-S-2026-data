#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],l,r,len,rm,ri,b,ans=0;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	ri=n;
	rm=a[n];
	for(int i=1;i<=n;i++){
		if(l>=len/2) break;
		if(l+a[i]>len/2) b=len/2-l;
		else b=a[i];
		while(rm-r<=b){
			if(c[ri]!=c[i]){
				ans+=(rm-r);
			}
			b-=(rm-r);
			r+=(rm-r);
			ri--;
			rm=rm+a[ri];
		}
		if(rm-r>b&&b>0){
			r+=b;
			if(c[ri]!=c[i]){
				ans+=b;
			}
		}
		l+=a[i];
	}
	cout<<ans;
	return 0;
}
