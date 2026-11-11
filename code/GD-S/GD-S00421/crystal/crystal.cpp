#include<bits/stdc++.h>
using namespace std;
#define int long long
#define filename "crystal"
int n,m,a[500005];
signed main(){
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int fcs=0,maxn=0,ifn=0;
	for(int i=1;i<n;i++){
		
		int now=a[i];
		fcs+=(now-a[i-1])*(i);
		//cout<<fcs<<endl;
		if(fcs>m){
			cout<<i;
			return 0;
		}
	}
	
	cout<<maxn;
	return 0;
}
