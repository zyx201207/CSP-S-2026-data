#include<bits/stdc++.h>
#define MAXN 513541
//#define long long long long
using namespace std;
long long arr[MAXN];
long long n,m;
long long pre[MAXN];
long long tot;
bool check(long long ind,long long from) {
	long long kk=(from-ind+1)*arr[from];
	long long tt=pre[from]-pre[ind-1];
	return (kk-tt)<=m;
}
long long search(long long from) {
	long long l=1,r=from,ans;
	while(l<=r) {
		long long mid=l+(r-l+1)/2;
		//cout<<mid<<endl;
		if (check(mid,from)) {
			ans=mid;
			r=mid-1;
		} else {
			l=mid+1;
		}
	}
	return ans;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>arr[i];
	sort(arr+1,arr+1+n);
	/*
	long long l=-1e12,r=1e12,ans;//二分目标水晶 
	while(l<=r) {
		
		long long mid=l+(r-l)/2;
		//cout<<mid<<endl;
		if (check(mid)) {//少了，可以更多 
			ans=mid;
			l=mid+1;
		} else {//多了 
			r=mid-1;
		}
	}
	for(long long i=1;i<=n;i++) {
		if (arr[i]<=ans) tot++;
	}*/
	for(long long i=1;i<=n;i++) pre[i]=pre[i-1]+arr[i];
	//cout<<search(4)<<endl;
	for(long long i=1;i<=n;i++) {
		long long cur=pre[i]-m;
		long long front=search(i),lst=upper_bound(arr+1,arr+1+i,arr[i]+1)-arr-1;
		//cout<<front<<" "<<lst<<endl;
		tot=max(tot,lst-front);
	}
	cout<<tot+1;
}
/*
5 5
10 10 15 15 15 
*/
