#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
ll n,a[N],e;
int l,r;
int ans;
int main(){
	 freopen("crystal.in","r",stdin);
	 freopen("crystal.out","w",stdout);
	cin>>n>>e;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	l=1,r=0;
	while(r<n){
		r++;
		e-=(r-l)*(a[r]-a[r-1]);
		while(e<0) e+=a[r]-a[l++];
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
//13min
