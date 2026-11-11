#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],p[200005],l,r,tot,ans;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		p[i]=p[i-1]+a[i];
	}
	tot=p[n];
	l=0;
	r=n-1;
	while(l<r){
		if(p[l]<tot-p[r]){
			l++;
			if(c[l]!=c[r+1]){
				if(p[l]<tot-p[r]){
					ans+=p[l]-p[l-1];
				}
				else{
					ans+=tot-p[r]-p[l-1];
				}
			}
		}
		else{
			r--;
			if(c[r+1]!=c[l]){
				if(tot-p[r]<p[l]){
					ans+=p[r+1]-p[r];
				}
				else{
					ans+=p[l]-tot+p[r+1];
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
