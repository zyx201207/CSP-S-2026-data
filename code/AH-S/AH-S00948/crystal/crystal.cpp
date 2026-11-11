#include<bits/stdc++.h>
using namespace std;
long long n,m,h,i,a[500009],b[500009],cut,ans;
vector<long long>mq;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	if(n%2!=0)h=a[n/2+1];else h=a[n/2];
	for(i=0;i<n;i++){
		b[i]=abs(h-a[i]);
		mq.push_back(b[i]);
	}
	sort(mq.begin(),mq.end());
	for(i=0;i<n;i++){
		cut+=mq[i];
		if(cut>m)break;
		ans++;
	}
	cout<<ans;
	return 0;
}
