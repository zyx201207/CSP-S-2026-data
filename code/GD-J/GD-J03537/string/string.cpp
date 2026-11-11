#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll n,ans;
vector<pair<ll,char>> a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	
	for(int i=1;i<=n;++i){
		pair<ll,char> x;
		cin>>x.first>>x.second;
		a.push_back(x);
	}
	
	ll l=0,r=n-1;
	while(l<r){
		//cout<<a[l].first<<" "<<a[l].second<<" "<<a[r].first<<" "<<a[r].second<<" "<<ans<<endl;
		if(a[l].second==a[r].second){
			if(a[l].first>a[r].first){
				a[l].first=a[l].first-a[r].first;
				r--;
			}else if(a[l].first<a[r].first){
				a[r].first=a[r].first-a[l].first;
				l++;
			}else{
				l++,r--;
			}
		}else{
			if(a[l].first>a[r].first){
				a[l].first=a[l].first-a[r].first;
				ans+=a[r].first;
				r--;
			}else if(a[l].first<a[r].first){
				a[r].first=a[r].first-a[l].first;
				ans+=a[l].first;
				l++;
			}else{
				ans+=a[l].first;
				l++,r--;
			}
		}
		
	}
	cout<<ans;
	return 0;
}

/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
