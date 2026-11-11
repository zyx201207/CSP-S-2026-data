#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[200005],sl,sr,sum;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	ll l=1,r=n;
	while(l<r){
		sum+=(c[l]!=c[r])*min(a[l],a[r]);
		if(a[r]>a[l])a[r]-=a[l],l++;
		else if(a[r]==a[l])l++,r--;
		else a[l]-=a[r],r--;
	}
	cout<<sum;
	return 0;
} 
