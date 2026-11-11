#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005],ans=0,n;
char c[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ll l=1,r=n;
	while(l<=r){
		if(a[l]<a[r]){
			if(c[l]==c[r])a[r]-=a[l],l++;
			else ans+=a[l],a[r]-=a[l],l++;
		}else if(a[l]>a[r]){
			if(c[l]==c[r])a[l]-=a[r],r--;
			else ans+=a[r],a[l]-=a[r],r--;
		}else if(a[l]==a[r]){
			if(c[l]==c[r])l++,r--;
			else ans+=a[l],l++,r--;
		}
	}cout<<ans;
	return 0;
} 
