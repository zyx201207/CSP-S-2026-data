#include <bits/stdc++.h>
using namespace std;
long long a[200005],b[200005];
long long c[35]={0,1,3,7,15,31,63,127,255,511,1023,204,4095,8191,16383,32767,65535,131071,262143,524287,1048575,2097151,4194303,8388607,16777215,33554431,67108863,134217727,268435455,536870911,1073741823};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,s=0,p=0;
	cin >> n >> m;
	for (long long i=1;i<=n;i++){
		cin >> a[i];
		for (int j=1;j<36;j++){
			if(a[i]==c[j]){
				b[++p]=a[i];
				break;
			}
		}
	}
	long long x=0,y=0;
	sort(a+1,a+n);
	for(int i=n;i>1&&m==2;i--){
		if(a[i]==a[i-1]){
			x=a[i];
			break;
		}
	}
	if(p>=m){
		sort(b+1,b+p+1);
		y=b[p-m+1];
	}
	long long z=a[n];
	for (int i=n-1;i>=n-m;i--){
		z&=a[i];
	}
	cout << max(x,max(y,z));
	return 0;
}
