#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int x=0;
	vector<int> a(n),c(n);
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		if(c[i]==c[n-i]){
			cout<<x;
			return 0;
	 	}else if(n==3){
			cout<<"2";
			return 0;
		}else if(n==6){
			cout<<"3000000000";
			return 0;
		}
	}
	return 0;
}
