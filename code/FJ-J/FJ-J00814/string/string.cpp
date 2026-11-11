#include<bits/stdc++.h>
using namespace std;
long long n,a[2000005],ans=0;
char c[2000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	while(l<r){
		if(a[l]==a[r]){
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			l++,r--;
		}else if(a[l]>a[r]){
			if(c[l]!=c[r]){
				a[l]-=a[r];
				ans+=a[r];
				r--;
			}else{
				a[l]-=a[r];
				r--;
			}
		}else if(a[l]<a[r]){
			if(c[l]!=c[r]){
				a[r]-=a[l];
				ans+=a[l];
				l++;
			}else{
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
