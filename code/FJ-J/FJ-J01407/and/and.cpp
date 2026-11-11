#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,sz[200005],maxn;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0; i<n; ++i){
		cin>>sz[i];
	}
	sort(sz,sz+n);
	int h;
	for(int i=0; i<n; ++i){
		h=sz[i];
		for(int j=i+1; j<=i+m-1; ++j){
			h&=sz[j];
		}
		maxn=max(h,maxn);
	}
	cout<<maxn;
	return 0;
}
