#include<bits/stdc++.h>
using namespace std;
const int N=5000005;
long long n,m,ans;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ans=1;ans<n;ans++){
		if(m<(a[ans+1]-a[ans])*ans) break;
		m-=(a[ans+1]-a[ans])*ans;
	}
	cout<<ans;
}
