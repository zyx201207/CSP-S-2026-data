#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
pair<int,char> a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		a[i].first=x,a[i].second=y;
		
	}
	int ans=0;
	int r=n;
	int l=1;
	int cnt=0;
	while(l<=r&&l<=n&&r>=1){
		if(l==r){
			break;
		}
		//cerr<<l<<" "<<a[l].first<<" "<<a[l].second<<endl;
		//cerr<<r<<" "<<a[r].first<<" "<<a[r].second<<endl<<endl;
		if(a[l].second==a[r].second){
			int lin=min(a[l].first,a[r].first);
			a[l].first-=lin;
			a[r].first-=lin;
		}
		else{
			ans+=min(a[l].first,a[r].first);
			int lin=min(a[l].first,a[r].first);
			a[l].first-=lin;
			a[r].first-=lin;
		}
		if(a[l].first==0){
			l++;
			//cerr<<'1'<<endl;
		}
		if(a[r].first==0) {
			//cerr<<2<<endl;
			r--;
		}
		cnt++;
	}
	cout<<ans;
	//cerr<<clock()-ddd;
	///cerr<<endl<<cnt;
}
