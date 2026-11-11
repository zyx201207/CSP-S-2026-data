#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500000+10],s[500000+10],sum=0,mx=0;
bool sf=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n-1;i++){
		s[i]=a[i+1]-a[i];
		if(s[i]!=s[i-1]){
			sf=false;
			break;
		}
	}
	if(sf){
		for(long long i=1;i<=n;i++){
			sum=(a[i]-a[i-1]+a[i]-a[1])*(i-1)/2;
			if(sum>m){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		sum=0;
		bool f=true;
		for(long long j=i-1;j>=1;j--){
			sum+=a[i]-a[j];
			if(sum>m){
				mx=max(mx,i-j);
				f=false;
				break;
			}
		}
		if(f){
			mx=max(mx,i);
		}
	}
	cout<<mx;
	return 0;
}
