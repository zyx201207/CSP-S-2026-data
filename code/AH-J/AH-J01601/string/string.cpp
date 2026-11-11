#include <bits/stdc++.h>
using namespace std;
int n,a[200005],l,r;
long long ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;r=n-1;
	for (int i=0;i<n;i++)	cin>>a[i]>>c[i];
	while(l<r)
		if(c[l]==c[r]){
			if(a[l]>a[r]){a[l]-=a[r];a[r]=0;r--;}
			else if(a[l]<a[r]){a[r]-=a[l];a[l]=0;l++;}
			else{a[l]=0;a[r]=0;l++;r--;}
		}
		else{
			if(a[l]>a[r]){ans+=a[r];a[l]-=a[r];a[r]=0;r--;}
			else if(a[l]<a[r]){ans+=a[l];a[r]-=a[l];a[l]=0;l++;}
			else{ans+=a[l];a[l]=0;a[r]=0;l++;r--;}
		}
	cout<<ans;
	return 0;
}
