#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	
	ll n,m,ans;
	cin>>n>>m;
	vector<ll>a(n+1);
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a.begin(),a.end(),greater<int>());
	if(m==1){
		cout<<a[0];	
		return 0;
	}
	ans=a[0];
	for(int i=0;i<m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0; 
} 
