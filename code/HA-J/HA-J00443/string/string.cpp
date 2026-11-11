#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n;
int a[N];
ll b[N];
char c[N];
ll len;
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=(ll)a[i];
		b[i]=a[i];
		b[i]+=b[i-1];
	}
	if(n==1){
		cout<<0;
		return 0;
	}	
	ll l=0,r=len+1;
	int lx=1,rx=n;
	while(1){
		ll lkz=b[lx]-l;
		ll rkz=r-(b[rx-1]+1);
//		cout<<lkz<<" "<<rkz<<" "<<lx<<" "<<rx<<" "<<l<<" "<<r<<"\n";
		ll kz=min(lkz,rkz);
		if(c[lx]!=c[rx]){
			ans+=kz;
		}
		l+=kz;r-=kz;
		if(l==b[lx]) lx++;
		if(r==b[rx-1]+1) rx--;
		if(l+1==r) break;
		if(lx==rx) break;
//		cout<<l<<" "<<r<<" "<<lx<<" "<<rx<<" "<<kz<<"\n";
	}
	cout<<ans;
	return 0;
}
