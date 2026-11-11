#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
long long n,a[N],l,r,ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n,l=1,r=n;
	for(long long i=1;i<=n;i++)cin>>a[i]>>c[i];
	while(l<r){
		long long minn=min(a[l],a[r]);
		if(c[l]!=c[r])ans+=minn;
		a[l]-=minn,a[r]-=minn;
		if(a[l]<=0)l++;
		if(a[r]<=0)r--;
	}
	cout<<ans;
	return 0;
}
