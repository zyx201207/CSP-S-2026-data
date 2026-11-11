#include<bits/stdc++.h>
using namespace std;
int n,z=1,ans;
long long m,a[500001],s;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s+=(i-z)*(a[i]-a[i-1]);
		while(s>m){
			s-=(a[i]-a[z]);
			z++;
		}
		ans=max(ans,i-z+1);
	}
	cout<<ans;
	return 0;
}
