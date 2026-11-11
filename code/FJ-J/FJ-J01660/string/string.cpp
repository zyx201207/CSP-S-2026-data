#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
long long ans;
int n,a[N],aq[N],ah[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		aq[i]=a[i]+aq[i-1];
		ah[i]=a[n-i+1]+ah[i-1];
	}
	int l=1,r=1,x=0;
	while(l<=n&&r<=n){
		if(aq[l]-x>ah[r]-x){
			if(c[l]!=c[n-r+1]) ans+=ah[r]-x;
			x=ah[r];
			r++;
		}
		if(aq[l]-x<ah[r]-x){
			if(c[l]!=c[n-r+1]) ans+=aq[l]-x;
			x=aq[l];
			l++;
		}
		if(aq[l]-x==ah[r]-x){
			if(c[l]!=c[n-r+1]) ans+=aq[l]-x;
			x=aq[l];
			l++,r++;
		}
	}
	cout<<ans/2;
	return 0;
}
