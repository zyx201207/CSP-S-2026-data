#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
long long n,m;
long long a[500500];
long long s[500500];
long long solve(long long i){
	long long l=1,r=i;
	if(i*a[i]-s[i]<=m)return 1;
	while(r-l>1){
		long long M=l+(r-l)/2;
		if((i-M+1)*a[i]-(s[i]-s[M-1])<=m)r=M;
		else l=M;
	}
	return r;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
	a[0]=0;s[0]=0;
    for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
    int ans=0;
    for(long long i=n;i>=1;i--){
		if(i-solve(i)+1>ans)ans=i-solve(i)+1;
	}
	cout<<ans;
	return 0;
}
