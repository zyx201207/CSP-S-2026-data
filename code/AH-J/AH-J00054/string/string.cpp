#include<bits/stdc++.h>
using namespace std;
long long s,n,a[200005],l,r;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	l=1;
	r=n;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]=a[l]-a[r];
				r--;
			}
			else if(a[r]>a[l]){
				a[r]=a[r]-a[l];
				l++;
			}
			else{
				l++;
				r--;
			}
		}
		else{
			if(a[l]>a[r]){
				a[l]=a[l]-a[r];
				s=s+a[r];
				r--;
			}
			else if(a[r]>a[l]){
				a[r]=a[r]-a[l];
				s=s+a[l];
				l++;
			}
			else{
				s=s+a[l];
				l++;
				r--;
			}
		}
	}
	cout<<s;
	return 0;
}

