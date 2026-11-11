#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],q[500001],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)q[i]=q[i-1]+a[i];
	for(long long l=0,r=1;r<=n;){
		if(m>=(a[r]*(r-l))-(q[r]-q[l])){
			ans=max(ans,r-l);
			r++;
		}else l++;
	}
	cout<<ans;
	return 0;
}
