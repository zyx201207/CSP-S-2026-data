#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
long long a[maxn];
string c[maxn]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	long long cnt=0;
	while(l<r){
		long long al=a[l];
		long long ar=a[r];
		if(c[r]!=c[l]){
			if(a[r]>a[l]){
				cnt+=a[l];
				a[r]-=a[l];
				a[l]=0;
				l++;
			}else if(a[r]<a[l]){
				cnt+=a[r];
				a[l]-=a[r];
				a[r]=0;
				r--;
			}else if(a[r]==a[l]){
				cnt+=a[l];
				a[r]=0;
				a[l]=0;
				l++;
				r--;
			}
		}else if(c[l]==c[r]){
			if(a[r]>a[l]){
				a[r]-=a[l];
				a[l]=0;
				l++;
			}else if(a[r]<a[l]){
				a[l]-=a[r];
				a[r]=0;
				r--;
			}else if(a[r]=a[l]){
				a[r]=0;
				a[l]=0;
				r--;
				l++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
