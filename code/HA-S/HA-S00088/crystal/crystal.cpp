#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
int n,k;
long long a[N],s[N];
long long ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	long long l,r,mid,cnt;
	for(int i=1;i<=n;i++){
		l=0,r=i-1,cnt=0;
		while(l<=r){
			mid=(l+r)>>1;
			if(((1LL*mid*a[i])-(s[i-1]-s[i-mid-1]))<=k){
				cnt=mid;
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		ans=max(ans,cnt+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
*/
