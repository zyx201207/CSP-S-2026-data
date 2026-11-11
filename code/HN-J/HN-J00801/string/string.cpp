#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[1000000];
char b[1000000];
int ans;
int l,r;
int len;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		len+=a[i];
	}
	l=1;
	r=n;
	int cnt=0;
	while(cnt<len/2){
		int o=min(a[l],a[r]);
		o=min(o,len/2-cnt);
//		cout<<l<<" "<<r<<" "<<o<<"\n";
		a[l]-=o;
		a[r]-=o;
		if(b[l]!=b[r]){
			ans+=o;
		}
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
		cnt+=o;
	}
	cout<<ans;
	return 0;
}
