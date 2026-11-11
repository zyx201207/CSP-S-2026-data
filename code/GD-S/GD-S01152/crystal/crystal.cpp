#include<bits/stdc++.h>
#define T_T return 0
using namespace std;
long long n,m;
long long a[500010];
long long s[500010];
bool check(long long mid)
{
	for(int i=mid;i<=n;i++)
	{
		long long sum=s[i]-s[i-mid];
		if(sum+m>=mid*a[i]) return true;
	}
	return false;
}
long long ef(long long l,long long r){
	while(l+1<r)
	{
		long long mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("srystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	cout<<ef(0,n+1);
	T_T; 
} 
