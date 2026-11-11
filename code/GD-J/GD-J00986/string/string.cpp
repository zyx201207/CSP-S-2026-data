#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n;
char c[N];
ll ans=0,a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int l=1,r=n;
	ll last=0,need=0;
	for(;l<=r;){
		if(last||need){
			if(last){
				ll x=min(a[l],last);
				a[l]-=x;
				last-=x;
				if(!last) need=a[l];
				if(c[l]!=c[r]) ans+=x;
			}else{
				ll x=min(a[r],need);
				a[r]-=x;
				need-=x;
				if(!need) last=a[r];
				if(c[l]!=c[r]) ans+=x;
			}
			if(last){
				l++;
			}else if(need){
				r--;
			}else{
				l++;
				r--;
			}
		}else{
			if(c[l]!=c[r]) ans+=min(a[l],a[r]);
			if(a[l]<a[r]){
				last=a[r]-a[l];
				l++;
			}else if(a[l]>a[r]){
				need=a[l]-a[r];
				r--;
			}else{
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
