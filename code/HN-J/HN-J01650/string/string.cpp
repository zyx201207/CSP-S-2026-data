#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=2e5+5;
int a[N];char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n,ans=0;
	while(l<=r){
		if(a[l]<=0){
			l++;
			continue;
		}
		if(a[r]<=0){
			r--;
			continue;
		}
		int min_=min(a[l],a[r]);
		a[l]-=min_;
		a[r]-=min_;
		if(c[l]!=c[r]) ans+=min_;
//		cout<<"[debug]:"<<l<<' '<<r<<' '<<ans<<' '<<min_<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
