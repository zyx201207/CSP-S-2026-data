#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5,M=1e18;
long long n,m,ans;
long long a[N];
long long q(long long zhi,long long id){
	long long k=m,cnt=0;
	for(long long i=id;i>=1;i--){
		k-=abs(zhi-a[i]); 
		if(k<0)break;
		cnt++;
	}
	return cnt;
}
void slove(){
	long long x1,x2;
	cin>>x1>>x2; 
	long long res=0,cnt=0;
	for(long long i=1;i<=n;i++){
		res*=2;
		res+=(x2-x1);
		if(res>m)break;
		cnt++;
	}
	cout<<min(cnt+1,n);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(m>M){
		slove();
		return 0;
	}
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		ans=max(ans,q(a[i],i));
	}
	cout<<ans;
	return 0;
}/*
5 8
-3 -1 2 2 7
*/

