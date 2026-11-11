#include<bits/stdc++.h>
using namespace std;
long long l,r,a[200010],n,ans;
char b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	l=1;
	r=n;
	while(l<=r){
		if(b[l]==b[r]){
			a[l]-=min(a[l],a[r]);
			a[r]-=min(a[l],a[r]);
		}else{
			ans+=min(a[l],a[r]);
			a[l]-=min(a[l],a[r]);
			a[r]-=min(a[l],a[r]);
		}
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<ans;
	return 0;
}
