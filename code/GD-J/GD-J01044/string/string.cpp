#include <bits/stdc++.h>
using namespace std;
const int N=1e5+3;
long long n;
int a[N];
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n ;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		cin >> b[i];
	}
	long long cnt=0;
	int l=1,r=n;
	while(l<=r){
		if(b[l]!=b[r]){
			if(a[l]>a[r] && a[r]!=0){
				b[l]=b[r];
				cnt+=min(a[l],a[r]);
				a[l]=a[l]-min(a[l],a[r]);
			
				a[r]=a[r]-min(a[l],a[r]);
			
				if(a[l]>0){
					r--;
					continue;
				}else if(a[r]>0){
					l++;
					continue;
				}
			}else if(a[l]<a[r] && a[l]!=0){
				b[r]=b[l];
				cnt+=min(a[l],a[r]);
				a[r]=a[r]-min(a[l],a[r]);
			
				a[l]=a[l]-min(a[l],a[r]);
	
				
				
				if(a[l]>0){
					r--;
					continue;
				}else if(a[r]>0){
					l++;
					continue;
				}
			}else if(a[l]==a[r] && a[l]!=0 && a[r]!=0){
				b[l]=b[r];
				cnt+=a[l];
				a[l]=0;
				a[r]=0;
			}
		}
		l++;
		r--;
	}
	cout << cnt;
}
