#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long r=n,l=n;
	long long s=0,mx=0;
	while(l>=1){
		s+=a[r]-a[l];
		while(s>m){
			s-=(r-l)*(a[r]-a[r-1]);
			r--;
		}
		mx=max(mx,r-l+1);
		l--;
	}
	cout<<mx;
}
