#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Seg{
	ll len;
	char c;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	vector<Seg>segs(n);
	for(int i=0;i<n;i++){
		ll x;
		char ch;
		cin>>x>>ch;
		segs[i].len=x;
		segs[i].c=ch;
	}
	
	int l=0,r=n-1;
	ll L=segs[l].len;
	ll R=segs[r].len;
	ll ans=0;
	ll left_rem=segs[l].len;
	ll right_rem=segs[r].len;
	while(l<r){
		ll take=min(L,R);
		if(segs[l].c!=segs[r].c){
			ans+=take;
			L-=take;
			R-=take;
			if(L==0){
				l++;
				if(l<=r)L=segs[l].len;
			if(R==0){
				r--;
				if(l<=r)R=segs[r].len;
			}
			}
		}
	cout<<ans;
	}
	return 0;
	}
