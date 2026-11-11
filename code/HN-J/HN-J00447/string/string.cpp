#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200010];
long long ans;
long long l,r,lc,rc;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	r=n;
	while(l<r){
		if(a[l]<=a[r]){
			if(c[l]==c[r]){
				a[r]-=a[l];
			}else{
				a[r]-=a[l];
				ans+=a[l];
			}
			l++;
		}else{
			if(c[l]==c[r]){
				a[l]-=a[r];
			}else{
				a[l]-=a[r];
				ans+=a[r];
			}
			r--;
		}
	}
	cout<<ans;
	return 0;
}
