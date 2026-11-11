#include <bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i]>>c[i];
	int l=0,r=n-1;
	long long ans=0;
	while(l<r){
		int f=0;
		if(a[l]>a[r]){
			if(c[l]!=c[r]) ans+=a[r];
			a[l]-=a[r];
			r--;
		}else if(a[l]<a[r]){
			if(c[l]!=c[r]) ans+=a[l];
			a[r]-=a[l];
			l++;
		}else if(a[l]==a[r]){
			if(c[l]!=c[r]) ans+=a[l];
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
