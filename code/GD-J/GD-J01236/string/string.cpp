#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
long long n;
long long a[N];
char c[N];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n/2;i++){
		if(c[i]!=c[n-i+1]){
			ans+=max(a[i],a[n-i+1]);
			a[n-i]-=abs(a[i]-a[n-i+1]);
		} 
	}
	cout<<ans;
	return 0;
} 
