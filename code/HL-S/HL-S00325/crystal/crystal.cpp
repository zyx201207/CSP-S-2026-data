#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(long long i=0;i<n-1;i++){
		if((a[i+1]-a[i])*(i+1)<=m){
			m-=(a[i+1]-a[i])*(i+1);
			ans++;
		}
		else break;
	}
	cout<<ans;
	return 0;
}
