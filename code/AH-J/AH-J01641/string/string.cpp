#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	unsigned long long cnt=0,l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]>=a[r]) {
				a[l]-=a[r];
				a[r]=0;
				r--;
			}
			else{
				a[r]-=a[l];
				a[l]=0;
				l++;
			}
		}
		else{
			if(a[l]>=a[r]) {
				a[l]-=a[r];
				cnt+=a[r];
				a[r]=0;
				r--;
			}
			else{
				a[r]-=a[l];
				cnt+=a[l];
				a[l]=0;
				l++;
			}
		}
	}
	cout<<cnt;
	return 0;
} 

