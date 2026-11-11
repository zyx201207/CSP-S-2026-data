#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll a[200010];
char c[200010];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	ll cnt=0;
	while(l<r){
		if(c[l]!=c[r]) cnt+=min(a[l],a[r]);
		if(a[l]<a[r]){
			a[r]-=a[l];
			l++;
		}
		else if(a[l]==a[r]){
			l++;
			r--;
		}
		else if(a[l]>a[r]){
			a[l]-=a[r];
			r--;
		}
	}
	cout<<cnt;
	return 0;
}