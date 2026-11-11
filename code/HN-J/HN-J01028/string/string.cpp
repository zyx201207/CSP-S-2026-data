#include<bits/stdc++.h>
using namespace std;
long long n,a[1000000],d[1000000],l,r,ans,xl,xr;
char c[10000000],lc,rc;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		d[i]=d[i-1]+a[i];
	}
	l=0,r=n,xl=0,xr=d[n];
	while(1){
		if(d[l+1]<d[n]+1-d[r-1]){
			l++;
			if(d[l]>d[n]/2){
				break;
			}
			long long len=d[l]-xl;
			xl+=len,xr-=len;
			if(c[l]!=c[r]){
				ans+=len;
			}
		}
		else{
			r--;
			if(d[r]<(d[n]+1)/2){
				break;
			}
			long long len=xr-d[r];
			xl+=len,xr-=len;
			if(c[l+1]!=c[r+1]){
				ans+=len;
			}
		}
	}
	if(d[l]>d[n]/2){
		if(c[l]!=c[l+1]){
			ans+=(d[n]/2-xl)-(xr-(d[n]+1)/2);
		}
	}
	else{
		if(c[l]!=c[l+1]){
			ans+=(xr-(d[n]+1)/2)-(d[n]/2-xl);
		}
	}
	cout<<ans;
	return 0;
}
