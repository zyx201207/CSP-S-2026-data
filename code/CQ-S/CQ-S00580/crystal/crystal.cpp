#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll=long long;
const int N=5e5+5;
int n,ans;
ll m,a[N],s[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,minn=i;
		while(l<=r){
			int mid=l+r>>1;
			if(((ll)i-mid+1)*a[i]-(s[i]-s[mid-1])<=m) minn=min(minn,mid),r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-minn+1);
	}
	cout<<ans;
	return 0;
}
