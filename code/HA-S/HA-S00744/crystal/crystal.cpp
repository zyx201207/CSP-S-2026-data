#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 5e5+10;

int n;
ll m;
ll a[maxn];
ll sum;
int ans=0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n);
	sum = a[1];
	for(int i=1,j=2,len=1;i<=n;++i){
		len = j-i;
		sum-=a[i-1];
		if(len==0){
			j=i+1;
			sum = a[i];
			len=1;
		}
		while(j<=n&&a[j]*len-sum<=m){
			sum+=a[j++];
			++len;
		}
		ans = max(ans,len);
	}
	cout<<ans;

	return 0;
}

