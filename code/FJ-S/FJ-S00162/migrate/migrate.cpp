#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+10;
const ll INF=0x3f3f3f3f3f3f3f3f;
int c,t;
int n;
ll d,x[N];
void solve(){
	cin >>n>>d;
	for(int i=1;i<=n;i++) cin >>x[i];
	vector<int> a;
	vector<pair<int,int>> kuai; 
	int la=1;
	for(int i=1;i<n;i++){
		if(i<=n-2&&x[i+2]-x[i]<=d&&(i==n-2||x[i+3]-x[i]>d)) a.push_back(i);
		if(x[i+1]-x[i]>d){
			if(la!=i) kuai.push_back({la,i});
			la=i+1;
		}
	}
	if(la!=n) kuai.push_back({la,n});
	ll ans=0;
	for(int k=0;k<kuai.size();k++){
		auto[l,r]=kuai[k];
		vector<int> b;
		b.push_back(l-3);
		for(int i=0;i<a.size();i++){
			if(a[i]>=l){
				if(a[i+1]+2<=r){if(a[i]+1==a[i+1]) b.push_back(a[i]);}
				else break;
			}
		}
		b.push_back(r);
		for(int i=1;i<b.size()-1;i++){
			ans+=max(1,(b[i]-b[i-1]-2))*max(1,(b[i+1]-b[i]-2));
//			cout << ans << '\n'; 
		}/*	
		for(int x:b) cout <<x << " ";
		cout <<'\n';*/
	}/*
	for(int x:a) cout <<x <<" ";
	cout << '\n';*/

	cout <<ans <<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >>c >>t;
	while(t--){
		solve();
	}
	return 0;
}
