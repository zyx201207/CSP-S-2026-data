#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,a[N],m,s[N],ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		int l=1,r=i;
		while(l<r){
			int mid=l+r>>1;
			int sum=a[i]*(i-mid);
			if(m>=sum-s[i-1]+s[mid-1])r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	//	cout<<i<<' '<<i-l+1<<'\n';
	}
	cout<<ans<<'\n';
    return 0;
}

