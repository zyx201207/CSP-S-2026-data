#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum,sumn,ans;
string c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=0,r=n-1;
	while(l<=r){
		while(min(a[l],a[r])){
			if(c[l]!=c[r]) ans+=min(a[l],a[r]);
			a[l]-=min(a[l],a[r]);
			a[r]-=min(a[l],a[r]);
		}
		if(a[l]<=0) l++;
		if(a[r]<=0) r--;
	}
	cout<<ans;
	return 0;
}
