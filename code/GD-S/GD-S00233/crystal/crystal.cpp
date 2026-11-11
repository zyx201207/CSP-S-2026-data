#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[500005],s,l=1,u;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s=s+a[i];
		while(a[i]*(i-l+1)-s>k){
			s=s-a[l];
			l++;
		}
		u=max(u,i-l+1);
	}
	printf("%lld",u);
	return 0;
} 
