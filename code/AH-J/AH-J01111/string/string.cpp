#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],sum=0,l=1,r;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=l+n-1;
	for(int i=1;i<=n;i++){cin>>a[i]>>c[i];}
	while(l<r){
		if(a[l]>a[r]&&c[l]!=c[r]){
			sum+=a[r];
			a[l]-=a[r];
			r--;
		}
		if(a[l]>a[r]&&c[l]==c[r]){
			a[l]-=a[r];
			r--;
		}
		if(a[l]==a[r]&&c[l]!=c[r]){
			sum+=a[r];
			r--;
			l++;
		}
		if(a[l]==a[r]&&c[l]==c[r]){
			r--;
			l++;
		}
		if(a[l]<a[r]&&c[l]!=c[r]){
			sum+=a[l];
			a[r]-=a[l];
			l++;
		}
		if(a[l]<a[r]&&c[l]==c[r]){
			a[r]-=a[l];
			l++;
		}
	}
	cout<<sum;
	return 0;
}
