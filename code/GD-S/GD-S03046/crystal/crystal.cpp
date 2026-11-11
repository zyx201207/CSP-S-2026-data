#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],mx,mi,x,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(a[i],mx);
		mi=min(a[i],mi);
	}
	long long l=mi,r=mx,mid=(mi+mx)/2;
	while(l<r){
		ans=0,x=0;
		for (int i=1;i<=n;i++){
			if(mid<a[i]) continue;
			x+=(mid - a[i]);
			ans++; 
		}
		if(x>m){
			r=mid;
		}
		else if(x<=m){
			l=mid+1;
		}
		
		mid=(l+r)/2;
	}
	cout<<ans<<endl;
	return 0;
} 
