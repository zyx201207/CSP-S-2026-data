#include <iostream>
#include <fstream>
using namespace std;
long long a[200005],c[200005],n,ans1,ans2;
char b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i]>>b[i];
		c[i]=a[i];
	}
	for(int l=1,r=n; l<r; l++){
		long long t=a[l];
		while(t){
			if(t>=a[r]){
				ans1 += a[r]*(b[r] != b[l]);
				t -= a[r] , r--;
			}else{
				ans1 += t*(b[r] != b[l]);
				a[r] -= t , t=0;
			}
		}
	}
	for(int r=n,l=1; l<r; r--){
		long long t=c[r];
		while(t){
			if(t>=c[l]){
				ans2 += c[l]*(b[r] != b[l]);
				t -= c[l] , l++;
			}else{
				ans2 += t*(b[r] != b[l]);
				c[l] -= t , t=0;
			}
		}
	}
	cout<<min(ans1,ans2);
	return 0;
}
