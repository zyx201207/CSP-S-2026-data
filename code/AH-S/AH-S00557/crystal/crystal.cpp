#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pii;
typedef unsigned long long ull;

int n;
int m;
vector<int> v;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	cin>>n>>m;
	v.resize(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	//if(n<=16) bao();
	vector<int> pre(n);
	pre[0]=v[0];
	for(int i=1;i<n;i++){
		pre[i]=pre[i-1]+v[i];
	}
	//for(auto& p:pre) cerr<<p<<' ';
	int ans=1;
	for(int i=1;i<n;i++){
		if(v[i]*i<=m+pre[i-1]){
			ans=i+1;
			//cerr<<ans<<' ';
		}
	}
	cout<<ans;
}
