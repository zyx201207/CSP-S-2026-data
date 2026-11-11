#include<bits/stdc++.h>
using namespace std;
int a[200005];char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int l=1,r=n;long long ans=0;
	while(l<=r){
		if(a[l]>a[r]){
			ans+=a[r]*(c[l]!=c[r]);
			a[l]-=a[r];
			r--;
		}else if(a[l]<a[r]){
	      	ans+=a[l]*(c[l]!=c[r]);
			a[r]-=a[l];
			l++;
		}else{
		    ans+=a[l]*(c[l]!=c[r]);
			l++;r--;
		}
	}
	cout<<ans;
	return 0;
}
