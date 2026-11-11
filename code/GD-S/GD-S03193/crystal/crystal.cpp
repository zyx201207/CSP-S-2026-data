#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long  n,m;
long long  a[N];
long long  s[N];
bool check(long long  ll,long long  rr){
	long long  res=(rr-ll+1)*a[rr]-(s[rr]-s[ll-1]);
	return res<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long  i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long  i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	long long  l=1,r=1;
	long long  mid=0;
	long long  ans=0;
	for(long long  i=1;i<=n;i++){
		l=1,r=i,mid=0;
		while(l<r){
			mid=(l+r)/2;
			if(check(mid,i)){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
}
