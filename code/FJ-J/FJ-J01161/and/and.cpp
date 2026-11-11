#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx=INT_MIN,s,t=1,b[10000005],ans;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>maxx){
				maxx=a[i];
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	maxx=INT_MIN;
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			b[t]=a[i] & a[j];
			t++;
		}
	}
	for(int i=1; i<=t-1; i++) {
		if(b[i]>maxx) {
			maxx=b[i];
		}
	}
	cout<<maxx<<"\n";
	return 0;
}

