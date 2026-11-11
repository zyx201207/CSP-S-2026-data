#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
long long a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,ans=0,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	long long x=a[1],y=a[n],i=1,j=n;
	while(i<=j){
		long long t=min(x,y);
		x-=t;
		y-=t;
		if(c[i]!=c[j]){
			ans+=t;
		}
		if(x==0){
			x=a[++i];
		}
		if(y==0){
			y=a[--j];
		}
	}
	cout<<ans;
	return 0;
}
