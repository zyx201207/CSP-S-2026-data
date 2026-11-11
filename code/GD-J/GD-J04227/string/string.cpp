#include <bits/stdc++.h>
using namespace std;
char c[200010];
long long a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("stding.out","w",stdout);
	long long n;cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
	}
	long long ans=0;
	int l=1,r=n;
	while(l<=r){
		if(a[l]>a[r]){
			ans+=a[r]*(c[l]!=c[r]);
			
			a[l]-=a[r];
			a[r]=0;
			r--;
		}else if(a[l]<a[r]){
			ans+=a[l]*(c[l]!=c[r]);
			a[r]-=a[l];
			a[l]=0;
			l++;
		}else{
			ans+=a[l]*(c[l]!=c[r]);
			a[l]=0,a[r]=0;
			l++,r--;
		}
		
	}
	
	cout << ans << endl;
} 
