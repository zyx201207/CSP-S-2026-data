#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],l=1,r,x=0,y=0;
long long ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	r=n;
	while(l<r){
		if(a[l]-x==a[r]-y){
			if(c[l]!=c[r]){
				ans+=a[l]-x;
			}
			x=0; y=0;
		}
		else{
			if(c[l]!=c[r]) ans+=min(a[l]-x,a[r]-y);
			if(a[l]-x<a[r]-y){
				y+=a[l]-x;
				x=0;
			}
			else{
				x+=a[r]-y;
				y=0;
			}
		}
		if(x==0) l++;
		if(y==0) r--;
	}
	cout<<ans;
	return 0;
}
