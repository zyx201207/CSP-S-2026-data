#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,c;
	int r=0,t;
	cin>>n>>m;
	vector<int>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int b=62;b>=0;b--){
		t=r|(1LL<<b);
		c=0;
		for(int i=0;i<n;i++){
			if((a[i]&t)==t&&++c>=m){
				break;
			}
		}
		if(c>=m){
			r=t;
		}
	}
	cout<<r;
	return 0;
}
