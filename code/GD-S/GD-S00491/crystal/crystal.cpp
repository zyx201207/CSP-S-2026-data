#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500000+10];
long long p=n;
long long u=1;
long long o=m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	o=m;
	p=n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=u;i--){
		if(p<=1)break;
		if(i==n){
			for(int j=n-1;j>=1;j--){
				if(o>=abs(a[n]-a[j])){
					p=j;
					u=n-j+1;
					o-=abs(a[n]-a[j]);
				}else break;
			}
			continue;
		}
		o+=abs(a[i]-a[i+1])*(i+1-p);
		for(int j=p-1;j>=1;j--){
			if(o>=abs(a[i]-a[j])){
				p=j;
				u=max(u,i-p+1);
				o-=abs(a[i]-a[j]);
			}else break;
		}
	}
	cout << u;
	return 0;
} 
