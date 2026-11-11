#include<bits/stdc++.h>
using namespace std;
#define int long long
#define filename "hub"
signed main(){
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int s;
		int m=(n-1)/2;
		if(10%(k+1)==0){
			s=10/(k+1)+1;
		}else{
			int yu=10%(k+1);
			int sh=10/(k+1);
			s=(yu/sh+1+sh)/2+1;
		}
		cout<<s<<endl;
	}
	
	
	
	
}
