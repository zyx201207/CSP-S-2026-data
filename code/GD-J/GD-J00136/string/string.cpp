#include <bits/stdc++.h>
#define int long long
using namespace std;
pair<int,char> a[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		a[i]={x,c};
	}
	int l=1,r=n,ans=0;
	while(l<r){
		if(a[l].first==0) l++;
		if(a[r].first==0) r--;
		if(a[l].second==a[r].second){
			int mn=min(a[l].first,a[r].first);
			a[l].first-=mn;
			a[r].first-=mn;
		}else{
			int mn=min(a[l].first,a[r].first);
			ans+=mn;
			a[l].first-=mn;
			a[r].first-=mn;
		}
	}
	cout<<ans;
	
	return 0;
} 
