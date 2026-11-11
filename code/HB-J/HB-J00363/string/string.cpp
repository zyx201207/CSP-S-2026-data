#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5;
ll n,a[N+10];
char c[N+10];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	ll l=1,r=n,sum=0;
	while(l<r){
		//~ cout<<l<<' '<<r<<' ';
		if(a[l]<a[r]){
			a[r]-=a[l],a[l]=0;
			if(c[r]!=c[l]) sum+=a[l];
			l++;
		}
		else if(a[l]>a[r]){
			a[l]-=a[r],a[l]=0;
			if(c[r]!=c[l]) sum+=a[r];
			r--;
		}
		else if(a[l]==a[r]){
			if(c[r]!=c[l]){
				sum+=a[r];
				//~ cout<<sum<<endl;
			}
			a[l]=0,a[r]=0;
			l++,r--;
		}
		//~ for(int i=1;i<=n;i++) cout<<a[i]<<' ';
		//~ cout<<endl;
	}
	cout<<sum;
	return 0;
}
