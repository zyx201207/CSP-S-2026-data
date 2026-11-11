#include<bits/stdc++.h>
using namespace std;
#define fre(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define pic pair<int,char>
#define ll long long
const int N = 2e5+5;
int n;
ll ans;
pic a[N];
int main(){
	fre("string");
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1;i<=n;i++) cin >> a[i].first >> a[i].second;
	int l = 1,r = n;
	while(l<r){
		int mn = min(a[l].first,a[r].first);
		if(a[l].second==a[r].second){
			a[l].first-=mn,a[r].first-=mn;
			if(a[l].first==0) l++;
			if(a[r].first==0) r--;
		}
		else{
			ans+=mn;
			a[l].first-=mn,a[r].first-=mn;
			if(a[l].first==0) l++;
			if(a[r].first==0) r--;
		}
	}
	cout << ans;
	return 0;
}
