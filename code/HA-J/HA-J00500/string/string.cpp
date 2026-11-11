#include<bits/stdc++.h>
using namespace std;
int n,a[200005],c[200005],l,r;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		char inc;
		cin>>a[i]>>inc;
		c[i]=inc-'a';
	}
	l=1,r=n;
	while(l<=r){
		if(a[l]==a[r]){
			if(c[l]==c[r]) l++,r--;
			else{
				ans+=a[l];
				l++,r--;
			}
		}else if(a[l]<a[r]){
			if(c[l]==c[r]){
				a[r]-=a[l];
				l++;
			}else{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
		}else{
			if(c[l]==c[r]){
				a[l]-=a[r];
				r--;
			}else{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
