#include<bits/stdc++.h>
#define  ll long long
#define  N 5e5;
int ans = 0;
using namespace std;

bool my_less(int a,int b){
	return a<b;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n = 0;
	ll  m = 0;
	vector<ll> a;
	cin>>n>>m;
	for(int i = 0; i<n; i++){
		long long t = 0;
		cin>>t;
		a.push_back(t);
	}
	sort(a.begin(),a.end(),my_less);
	for(int i = 1; i < n; i++){
		auto ll it = a[i-1];
		ll cost=0;
		int cnt=0;
		int pos=i-1;
		while(pos+1){
			if(cost + (a[i]-it) <= m){
				cost+=it;
				cnt++;
			}
			pos--;
			it--;
		}
		if(cnt > ans) ans = cnt;
	}
	cout<<ans+1;
	return 0;
} 
