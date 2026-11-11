#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000001],t=0,sum=0,ans=0,x,y;
queue<long long> q;
bool gz(long long x,long long y) {
	return x<y;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1,gz);
	q.push(a[1]);
	for(long long i=2;i<=n;i++) {
		y=q.size();
		x=q.back();
		t+=(a[i]-x)*y;
		if(t<=m) {
			sum++;
			q.push(a[i]);
		} else {
			while(1) {
				x=q.front();
				q.pop();
				t=t-(a[i]-x);
				sum--;
				if(t<=m) break;
			}
			sum++;
			q.push(a[i]);
		}
		ans=max(ans,sum);
	}
	cout<<ans+1;
	return 0;
}
