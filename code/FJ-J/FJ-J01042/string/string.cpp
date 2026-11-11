#include<bits/stdc++.h>
using namespace std;
long long a[200010],l,r,sl,s,ans;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	l=1,r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s+=a[i];
	}
	long long h=s>>1;
	while(sl+a[l]<=h){
		sl+=a[l];
		while(a[l]){
			if(a[l]>=a[r]){
				if(c[l]!=c[r]){
					ans+=a[r];
				}
				a[l]-=a[r];
				r--;
			}else{
				if(c[l]!=c[r]){
					ans+=a[l];
				}
				a[r]-=a[l];
				a[l]=0;
			}
		}
		l++;
	}
	while(r>l){
		if(c[l]!=c[r]){
			ans+=a[r];
		}
		r--;
	}
	cout<<ans;
}
