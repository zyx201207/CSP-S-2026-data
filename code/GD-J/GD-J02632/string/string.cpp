#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char c[200005];
long long cnt,l,r;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	l=1;r=n;
	while(l<r){
		long long mi=min(a[l],a[r]);
		if(c[l]!=c[r]) cnt+=mi;
		a[l]=a[l]-mi;
		a[r]=a[r]-mi;
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<cnt;
	return 0;
}
