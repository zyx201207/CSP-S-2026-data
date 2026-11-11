#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+10;
int n,a[N],s[N],ans,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		int l=1,r=i,o=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if((s[i]-s[mid-1])+m>=(i-mid+1)*a[i]) r=mid-1,o=mid;
			else l=mid+1;
		}
		if(o!=-1) ans=max(ans,i-o+1);
	}
	cout<<ans<<endl;
	return 0;
} 
