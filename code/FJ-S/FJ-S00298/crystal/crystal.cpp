#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],s[N],n,m;
int ask(int x){
	int l=x,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		int sum=(mid-x-1)*a[mid]-(s[mid-2]-s[x-1]);
//		cout<<x<<" "<<mid<<" "<<sum<<endl;
		if(sum<=m){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	return l;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
//		cout<<s[i]<<' ';
	}
//	cout<<endl;
	int ans=0;
	for(int i=1;i<=n;i++){
		int t=ask(i);
		ans=max(ans,t-i+1);
//		cout<<i<<" "<<t<<endl;
	}
	cout<<ans;
	return 0;
}
