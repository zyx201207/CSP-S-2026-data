#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll a[500005],diff[500005];
map<ll,ll> mp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		diff[i]=a[i]-a[i-1];
	}
	sort(a+1,a+1+n);
	int j=2;
	while(m>0){
		if(diff[j]<=0){
			j++;
		}
		m=m-j+1;
		if(m>=0){
			diff[1]++;
			diff[j]--;
		}
		if(m<0){
			diff[1]++;
			diff[m+1]--;
			break;
		}
	}
	int cur=0;
	for(int i=1;i<=n;i++){
		cur+=diff[i];
		mp[cur]++;
	}
	for(auto s : mp){
		cout<<s.second;
		break;
	}
	return 0;
}
