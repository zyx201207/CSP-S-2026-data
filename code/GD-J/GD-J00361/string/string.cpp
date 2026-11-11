#include<bits/stdc++.h>
#include<cstdio>
using namespace std; 
long long cnt=0,n,l,r; 
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}r=n-1;
	while(l<=r){
		if(c[l]!=c[r]){
			if(a[l]>a[r]){
				cnt+=a[r];
				a[l]-=a[r];
				a[r]=0;
				r--;
			}else if(a[l]<a[r]){
				cnt+=a[l];
				a[r]-=a[l];
				a[l]=0;
				l++;
			}else{
				cnt+=a[r];
				a[r]=0,a[l]=0;
				l++,r--;
			}
		}else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				a[r]=0;
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				a[l]=0;
				l++;
			}else{
				a[r]=0,a[l]=0;
				l++,r--;
			}
		}
	}cout<<cnt;
	return 0;
}
