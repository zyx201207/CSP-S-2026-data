#include<bits/stdc++.h>
using namespace std;
long long n,s=0;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	while(l<=r){
		if(a[l]<=a[r]){
			if(c[l]!=c[r]){
				s+=a[l];
			}
			a[r]-=a[l];
			a[l]=0;
		}
		if(a[l]>a[r]){
			if(c[l]!=c[r]){
				s+=a[r];
			}
			a[l]-=a[r];
			a[r]=0;
		}
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
	}
	cout<<s;
	return 0;
} 
