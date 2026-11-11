#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	vector<int> a(n,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end(),greater<int>());
	if(n==m){
		ll t=a[0];
		for(int i=0;i<n;i++){
			t&=a[i];
		}	
		cout<<t;
	}else if(m==1){	
		cout<<a[0];
	}else if(m==n-1){	
		ll t=a[0];
		for(int i=0;i<n-1;i++){
			t&=a[i];
		}	
		cout<<t;
	}else if(m==2){	
		cout<<(a[0]&a[1]);
	}else{	
		ll t=a[0];
		for(int i=0;i<m;i++){
			t&=a[i];
		}	
		cout<<t;
	}
	
	return 0;
}
