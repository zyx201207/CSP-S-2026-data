#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
int n,m,x=-1e18,ans;
int a[N];
bool cmp(int p,int q){
	return p>q;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		x=max(x,a[i]);
	}
	if (m==1){
		cout<<x<<'\n';
		return 0;
	}else if (m==n){
		for (int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans<<'\n';
	}else{
		sort(a+1,a+1+n,cmp);
		int res=a[1];
		for (int i=2;i<=m;i++){
			res=res&a[i];
		}
		cout<<res<<'\n';
	}
 	return 0;
}
