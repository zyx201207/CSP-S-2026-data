#include<bits/stdc++.h>
using namespace std;
const int xy=222222;
int n,l,r;
long long u[xy],s[xy],j,e;
char c[xy];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>c[i];
		s[i]=u[i]+s[i-1];
	}
	l=1;
	r=n;
	while(l<r){
		long long xl=s[l],xr=s[n]-s[r-1];
		if(c[l]==c[r]){
			if(xl<=xr){
				j=xl;
				l++; 
			}else{
				j=xr;
				r--;
			}
		}else{
			if(xl<=xr){
				e+=(xl-j);
				l++;
				j=xl;
			}else{
				e+=(xr-j);
				r--;
				j=xr;
			}
		}
	}
	cout<<e;
	return 0;
}
