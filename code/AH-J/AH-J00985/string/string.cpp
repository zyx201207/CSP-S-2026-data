#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string ikun="woshixiaohezi";//I'm true ikun
const int maxn=1e6+10;
ll n,a[maxn],len,l,r,sl,sr,pos,ans;
char c[maxn];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	l=1;
	r=n;
	sl=a[1];
	sr=a[n];
	len/=2;
	while(1){
		if(l>=r)break;
		pos=min(sl,sr);
		sl-=pos;
		sr-=pos;
		if(c[l]!=c[r])ans+=pos;
		if(sl==0){
			l++;
			sl=a[l];
		}
		if(sr==0){
			r--;
			sr=a[r];
		}
	}
	cout<<ans;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    solve();
    return 0;
}
//Trick||Treat!
