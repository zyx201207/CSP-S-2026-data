#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll m;
ll n;
ll a[500006];
unordered_map<ll,int> b;
ll t;
ll y;
ll ans=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	cin>>m;
	for(int i = 1;i<=n;++i){
		cin>>a[i];
		b[a[i]]++;
	}
	sort(a+1,a+1+n);
	for(int i = 2;i<=n;i+=(i==2&&b[a[i]]!=1?(-1):0)+b[a[i]]){
		y=0;
		t=m;
		for(int j = i-1;j>0&&t>0;--j){
			if(t<a[i]-a[j]){
				break;
			}
			if(j==1&&a[i]==a[j])y--;
			y++;
			t-=a[i]-a[j];
		}
		ans=max(ans,y+b[a[i]]);
	}
	cout<<ans;
	return 0;
}
