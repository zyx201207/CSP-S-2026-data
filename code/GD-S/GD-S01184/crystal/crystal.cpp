#include<bits/stdc++.h>
using namespace std;
int lz;
long long n,m;
long long e;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int l=1,r=2;r<=n;r++){
		if(e+(a[r]-a[r-1])*(r-l)>m){
			lz=max(r-l,lz);
			e+=(a[r]-a[r-1])*(r-l);
			for(;l<=r;l++){
				e-=(a[r]-a[l]);
				if(e<m){
					l++;
					break;
				}
			}
			continue;
		}
		e+=(a[r]-a[r-1])*(r-l);
		if(r==n){
			lz=max(lz,r-l+1);
		}
	}
	cout<<lz;
	return 0;
}
