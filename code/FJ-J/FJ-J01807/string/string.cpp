#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
char c[N];
ll a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	ll szl=a[1],szr=a[n];
	ll cnt=0;
	while(l<r){
		if(c[l]!=c[r]){
			cnt+=min(szl,szr);
		}
		if(szl>szr){
			szl-=szr;
			r--;
			szr=a[r];
		}
		else if(szl<szr){
			szr-=szl;
			l++;
			szl=a[l];
		}
		else{
			l++;
			r--;
			szr=a[r];
			szl=a[l];
		}
	}
	cout<<cnt;
	return 0;
}
