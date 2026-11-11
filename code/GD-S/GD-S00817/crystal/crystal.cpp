#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans,b[500010];
bool A,B;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];  
		if(a[i]!=i) A=0;
		if(i>=3&&a[i]-a[i-1]!=a[2]-a[1]) B=0;
	}
	if(A==1) {
		for(int i=0;i<n;i++) {
			m-=i;
			if(m<0) {
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	if(B==1) {
		for(int i=0;i<n;i++) {
			m-=i*abs(a[2]-a[1]);
			if(m<0) {
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) {
		long long z=m,s=1;
		for(int j=i-1;j>=1;j--) {
			if(z<a[i]-a[j]) break;
			z-=a[i]-a[j];
			s++;
		}   
		ans=max(ans,s);
	}   
	cout<<ans;
	return 0;
}

