//GZ-S00241,娄芷淇,贵阳市第一中学 
#include<bits/stdc++.h>
using namespace std;
long long maxnum,n,m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	bool f=0;
	for(long long i=2;i<=n;i++){
		long long cnt=0;
		for(long long j=i-1;j>=1;j--){
			cnt=cnt+a[i]-a[j];
		}
		if(cnt<=m){
			maxnum=i;
			f=1;
		}
		if(cnt>m) break;
	}
	if(f==0) cout<<1;
	else cout<<maxnum;
	return 0;
}
