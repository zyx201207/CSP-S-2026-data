#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],s[N],n,m;
bool check(int x){
	bool f=0;
	for(int i=x;i<=n;i++){
		int tmp=a[i]*x-(s[i]-s[i-x-1]);
		if(tmp<=m){
			f=1;
		}
	}
	return f;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
