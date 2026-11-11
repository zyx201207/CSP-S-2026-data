#include<bits/stdc++.h>
using namespace std;
#define tt long long
tt n,m,a[500005],b[500005],mx=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(tt i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(tt i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	tt l=1,r=2;
	while(r<n){
		if(a[r]-a[l]>m){
			l++;
		}
		else{
			mx=max(r-l,mx);
			r++;
		}
	}
	cout<<mx+1;
}
 
