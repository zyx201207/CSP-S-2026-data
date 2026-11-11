#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long s[500010];
bool check(long long x){
	for(int i=x;i<=n;i++){
		if((a[i]*x-(s[i]-s[i-x]))<=m) return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	long long l=1,r=n;
	while(l<r){
		long long mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<r<<"\n";
	return 0;
}

/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
