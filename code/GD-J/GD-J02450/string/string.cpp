#include <bits/stdc++.h>
#define ll long long
#define PAIR pair<long long,char>
using namespace std;
const int N = 200005;
ll n;
PAIR a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	ll l=1,r=n,cnt=0;
	while(l<r){
		ll k=min(a[l].first,a[r].first);
		if(a[l].second != a[r].second){
			cnt+=k;
		}
		a[l].first-=k;
		a[r].first-=k;
		if(a[l].first<=0) l++;
		if(a[r].first<=0) r--;
	}
	cout<<cnt;
	return 0;
}
