#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll num[200005];
char chr[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>num[i]>>chr[i];
	ll l=0,r=n-1;
	ll cnt=0;
	while(1){
		if(l==r) break;
		if(chr[l]==chr[r]){
			ll t=min(num[l],num[r]);
			num[l]-=t;
			num[r]-=t;
			if(num[l]==0) l++;
			if(num[r]==0) r--;
		}else{
			int t=min(num[l],num[r]);
			cnt+=t;
			num[l]-=t;
			num[r]-=t;
			if(num[l]==0) l++;
			if(num[r]==0) r--;
		}
	}
	cout<<cnt;
	return 0;
}
