#include <bits/stdc++.h>
using namespace std;
const long long MAXN=5e5+5;
long long a[MAXN];
long long s[MAXN];
long long n,m;
bool check(int x,int i){
	return a[i]*(i-x+1)-(s[i]-s[x-1])<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	long long mx=0;
	for(long long i=n;i>=1;i--){
		if(a[i]==a[i+1]) continue;
		long long l=1,r=i,ans=i;
		while(l<=r){
			long long mid=l+(r-l)/2;
			if(check(mid,i)){
				ans=mid;
				r=mid-1;
			}else l=mid+1;
		}
		mx=max(mx,i-ans+1);
	}
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 5
1 2 4 8 9

*/
