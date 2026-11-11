#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],num,l,r;
char c[200005];
int main(){
	freopen("string.in",'r',stdin);
	freopen("string.out",'w',stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	l=0;
	r=n-1;
	while(l<r){
		if(a[l]<a[r]){
			if(c[l]!=c[r]){
				num+=a[l];
			}
			a[r]-=a[l];
			a[l]=0;
			l++;
		}else{
			if(c[l]!=c[r]){
				num+=a[r];
			}
			a[l]-=a[r];
			a[r]=0;
			r--;
		}
	}
	cout<<num;
	return 0;
}
