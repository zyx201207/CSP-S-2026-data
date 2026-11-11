#include<bits/stdc++.h>
using namespace std;
long long a[500005],q[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		q[i]=q[i-1]+a[i];
	}
	long long cnt=-1;
	for(long long r=1,l=1;r<=n&&l<=r;){
		long long x=(r-l+1)*a[r]-q[r]+q[l-1];
		if(x<=m){
			cnt=max(cnt,r-l+1);
			r++;
		}else l++;
	}cout<<cnt;
	return 0;
}

