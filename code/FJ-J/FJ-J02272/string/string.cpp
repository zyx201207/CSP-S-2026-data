#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010];
char b[500010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		m=m+a[i];
	}
	m=m/2;
	int r=1,l=n,k=0,o=0;
	while(o!=m){
		int ss;
		if(a[r]>=a[l]){
			ss=a[l];
		}else{
			ss=a[r];
		}
		o+=ss;
		if(o>m){
			ss-=o-m;
			o=m;
		}
		if(b[r]!=b[l]){
			k=k+ss;
		}
		a[r]=a[r]-ss;
		a[l]=a[l]-ss;
		if(a[r]==0){
			r++;
		}
		if(a[l]==0){
			l--;
		}
	}
	cout<<k;
	return 0;
}
