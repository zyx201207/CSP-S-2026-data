#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans=0;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	while(l<r){
		if(a[l]==a[r]){
			if(c[l]==c[r]){
				l++;
				r--;
			}else{
				ans+=a[l];
				l++;
				r--;
			}
		}else{
			if(a[l]>a[r]){
				if(c[l]==c[r]){
					a[l]-=a[r];
					r--;
				}else{
					ans+=a[r];
					a[l]-=a[r];
					r--;
				}
			}else{
				if(a[r]>a[l]){
					a[r]-=a[l];
					if(c[l]!=c[r]){
						ans+=a[l];
					}
					l++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
