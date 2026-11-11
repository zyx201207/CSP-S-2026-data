#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long mx=1;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	long long cha=0;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cha=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=cha) f=0;
	}
	cha=abs(cha);
	if(f){
		long long dcs=0;
		for(int i=1;i<=n;i++){
			if(m-(i-1)*cha>=0) m-=(i-1)*cha,dcs++;
			else break;
		}
		cout<<dcs;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long x=m;
		long long c=0;
		for(int j=i;j>=1;j--){
			if(x-(a[i]-a[j])>=0) c++,x-=(a[i]-a[j]);
			else break;
		}
		mx=max(mx,c);
	}
	cout<<mx;
	return 0;
}

