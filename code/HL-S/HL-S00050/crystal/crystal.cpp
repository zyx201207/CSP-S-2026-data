#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+10;
int n;
LL m,a[N],s[N];
int ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		int l=1,r=i;
		while(l<r){
			int mid=l+r>>1;
			if(a[i]*(i-mid)-s[i-1]+s[mid-1]<=m)r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<'\n';
	return 0;
}
