#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n;
ll m,a[N],sum;
struct node{
	ll q;
	int l;
}s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int ans=1;
	s[1].q=0;
	s[1].l=1;
	for(int i=2;i<=n;i++){
		s[i].q=s[i-1].q+(i-1)*(a[i]-a[i-1]);
	}
	for(int i=2;i<=n;i++){
		int l=1,r=i,mid;
		sum=0;
		while(l<r){
			mid=(l+r)>>1;
			sum=s[i].q-s[mid-1].q-s[mid-1].l*(a[i]-a[mid]);
			if(sum>m){
				l=mid+1;
			}else{
				r=mid;
			}
		}
		if(sum<=m) ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
}
