#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],s,r,mm,mx,c;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int f=0,ff=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) f=1;
		if(i>=3 && ((a[2]-a[1])!=(a[i]-a[i-1]))) ff=1;
	}
	if(f==0){
		for(int i=1;i<=n;i++){
			if(m<(i*(i+1)/2)){
				cout<<i;
				return 0;
			}
		}
	}
	c=a[2]-a[1];
	if(ff==0){
		for(int i=1;i<=n;i++){
			if(m<(i*(i+1)/2*c)){
				cout<<i;
				return 0;
			}
		}
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){	
		r=i-1,s=1,mm=m;
		for(int j=1;j<=i+1;j++){
			if(r==0){
				mx=max(mx,s);
				continue;
			}
			if(a[i]-a[r]<=mm){
				s++;
				mm-=(a[i]-a[r]);
			}
			else{
				mx=max(mx,s);
				continue;
			}
			r--;
		}
	}
	cout<<mx;
	return 0;
}
