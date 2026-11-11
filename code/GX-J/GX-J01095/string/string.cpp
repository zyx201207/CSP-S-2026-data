#include<bits/stdc++.h>

using namespace std;
long long n,a[200005],d=0,ans=0;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		d+=a[i];
	}
	for(long long i=1;i<=(n+1)>>1;i++){
		if(c[i]!=c[n-i+1]){
			ans+=min(a[n-i+1],a[i]);
			if(n&1)ans+=abs(a[i]-a[n-i+1]);
		}
	}
	cout<<ans;
	
    return 0;
}
