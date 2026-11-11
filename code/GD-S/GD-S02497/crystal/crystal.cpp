#include<bits/stdc++.h>
using namespace std;
#define For(i,s,e) for(int i=s;i<=e;i++)
#define dFor(i,s,e) for(int i=s;i>=e;i--)
#define int long long
const int M=5e5+10;
int n,m,a[M];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	For(i,1,n)scanf("%lld",a+i);
	sort(a+1,a+n+1);
	int s=0,l=1,mx=0;
	For(i,2,n){
		s+=(a[i]-a[i-1])*(i-l);
		while(s>m)s-=a[i]-a[l++];
//		cout<<a[i]<<" "<<s<<" "<<i<<" "<<l<<endl;
		mx=max(mx,i-l+1);
	}
	printf("%lld",mx);
	return 0;
}

