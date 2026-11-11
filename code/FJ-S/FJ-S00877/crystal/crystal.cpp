#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005];
int main() {
	int ans;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=a[n]-a[i];
	}
	for(int i=1;i<=n;i++){
		int res=0,x=b[i],y=m;
		for(int j=i;j>=1;j--){
			y-=(b[j]-b[i]);
			if(y>=0) res++;
			else break;
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
}
