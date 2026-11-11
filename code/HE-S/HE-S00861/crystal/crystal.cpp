#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],d;
int n,m;
int cnt[N];
int check1(int w) {
	int sum=0,c=cnt[w];
	for(int i=w-1; i>=0; i--) {
		sum+=(w-i)*cnt[i];
		if(sum>m) {
			sum-=(w-i)*cnt[i];
			int rest=m-sum;
			c+=rest/(w-i);
			break;
		}
		c+=cnt[i];
	}
	return c;
}
int check(int j) {
	int sum=0,c=1;
	for(int i=j-1; i>=1; i--) {
		sum+=(a[j]-a[i]);
		if(sum>m)break;
		c++;
	}
	return c;

}
bool check2(int mid) {
	return mid*(mid+1)*d<=2*m;
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n<=5000) {
		for(int i=1; i<=n; i++)cin>>a[i];
		sort(a+1,a+n+1);
		int ans=0;
		for(int i=1; i<=n; i++)ans=max(ans,check(i));
		cout<<ans;
	} else {
		long long mx=0;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
			a[i]+=100;
			mx=max(mx,a[i]);
			if(a[i]<=200) cnt[a[i]]++;
		}
		if(mx<=200) {
			int ans=0;
			for(int i=0; i<=mx; i++)ans=max(ans,check1(i));
			cout<<ans;
		} else {
			d=a[2]-a[1];
			int l=0,r=n-1;
			while(l<r) {
				int mid=l+r+1>>1;
				if(check2(mid))l=mid;
				else r=mid-1;
			}
			cout<<r+1;
		}
	}
	return 0;
}
