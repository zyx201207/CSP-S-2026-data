#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,l,r,ans,a[200005];
char c[200005];

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	
	l=1;
	r=n;
	
	while(l<r){
		int x=abs(a[l]-a[r]);
		if(x==0){
			x=a[l];
		}
		if(c[l]!=c[r]){
			ans+=x;
		}
		a[l]-=x;
		a[r]-=x;
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
	}
	
	cout<<ans;
	
	return 0;
}
