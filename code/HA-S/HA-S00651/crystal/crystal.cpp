#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],x=0,z=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(a[1]==a[n]){
		cout<<n;
		return 0;
	}
	if(a[3]*2-(a[2]+a[1])<m){
		cout<<2;
		return 0;
	}
	for(int i=2;i<=n;i++){
		long long s=1;
		x+=a[i]+a[i-s];
		if(a[i+1]*i-x>m){
			for(int j=i;j<=n;j++){
				if(a[i+1]==a[j]){
					z++;
				}
			}
			cout<<i+z-1;
			break;
		}
		++s;
	}
	return 0;
}
