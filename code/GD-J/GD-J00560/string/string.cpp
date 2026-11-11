#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,ans;
pair<int,char>a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
	int l=1,r=n,ll=a[1].first,lr=a[n].first;
	while(l<r){
		if(a[l].second==a[r].second){
			int m=min(ll,lr);
			ll-=m,lr-=m;
		}
		else{
			int m=min(ll,lr);
			ll-=m,lr-=m;
			ans+=m;
		}
		if(ll==0) ll=a[++l].first;
		if(lr==0) lr=a[--r].first;
	}
	cout<<ans;
	return 0;
}
