#include <bits/stdc++.h>
using namespace std;
long long a[500005],n,m,s=0,d;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		d=0;
		for(int j=1;j<=i;j++){
			d+=a[i]-a[j];
		}
		if(d>=m){
			cout<<i+1;
			return 0;
		}
	}
	return 0;
}
