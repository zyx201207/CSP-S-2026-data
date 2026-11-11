#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],s[N],ans;
int sum(int l,int r){
	return s[r]-s[l-1];
}
void sol(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int le=1,ri=i,res=i;
		while(le<=ri){
			int mid=(le+ri)/2;
//			cerr<<le<<" "<<ri<<" "<<mid<<"\n";
			if((i-mid+1)*a[i]-sum(mid,i)<=m){
				ri=mid-1;
				res=mid;
			}
			else{
				le=mid+1;
			}
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int ct=1;
	while(ct--){
		sol();
	}
}
