#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans=-1,da;
long long yu(long long x,long long y){
	x&=y;
	return x;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		da=max(da,a[i]);
	}
	if(m==1){
		cout<<da;
		return 0;
	}
	if(n==m){
		long long bzd=a[1];
		for(int i=2;i<=n;i++){
			bzd=yu(bzd,a[i]);
		}
		cout<<bzd;
		return 0;
	}
	bool f1=1;
	for(int i=1;i<=n;i++){
		if(a[i]>=4) f1=0;
	}
	if(f1==1){
		long long one=0,two=0,three=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) one++;
			else if(a[i]==2) two++;
			else if(a[i]==3) three++;
		}
		if(three>=m) cout<<3;
		else if(two+three>=m) cout<<2;
		else if(one+three>=m) cout<<1;
		else cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
	return 0;
}
