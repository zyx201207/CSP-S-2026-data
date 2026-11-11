#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}int l=1,r=n;
	while(l<=r){
		if(c[l]!=c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				ans+=a[r];
				r--;
			}else if(a[l]==a[r]){
				ans+=a[r];
				l++;
				r--; 
			}else {
				a[r]-=a[l];
				ans+=a[l];
				l++;
			}
		}else {
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if(a[l]==a[r]){
				l++;
				r--; 
			}else {
				a[r]-=a[l];
				l++;
			}
		}
	}cout<<ans;
	return 0;
}
