#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,m;
vector<ll int> ns;

bool cmp(ll int a,ll int b){
	return a>b;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		ll int tmp;
		cin>>tmp;
		ns.push_back(tmp);
	}
	
	sort(ns.begin(),ns.end(),cmp);

	ll int ans=ns[0];
	for(int i=1;i<m;i++){
		ans = ans&ns[i];
	}
	cout<<ans;
	return 0;
}
