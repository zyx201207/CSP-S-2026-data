#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll m,a[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	ll s=0,t=0,l=1;
	for(int i=1;i<=n;i++){
		t=(i-l+1)*ll(a[i]);
		s+=a[i];
		if(t-s>m){
			ans=max(ans,i-l);
			s-=a[l++];
		}
	}if(ans!=0)cout<<ans;
	else cout<<n;
	return 0;
}/*
5 8
-3 -1 2 2 7
5 5
1 2 4 8 9
9 10
1 2 3 4 4 4 4 4 4
*/
