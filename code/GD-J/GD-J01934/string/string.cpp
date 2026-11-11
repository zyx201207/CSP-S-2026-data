#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
char c[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	long long l=0,r=n-1;
	long long ans=0;
	while(l<r){
		if(c[l]!=c[r]){
			if(a[r]>a[l]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}else if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}else if(a[l]==a[r]){
				ans+=a[l];
				l++;r--;
			}
		}else{
			l++;r--;
		}
	}
	cout<<ans;
	return 0;
}
