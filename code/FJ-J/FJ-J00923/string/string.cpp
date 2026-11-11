#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],z;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	if(n%2==1){
		while(l!=r){
			if(a[l]==a[r]){
				if(c[l]!=c[r])z+=a[l];
				l++;
				r--;
			}else if(a[l]>a[r]){
				if(c[l]!=c[r])z+=a[r];
				a[l]-=a[r];
				r--;
			}else{
				if(c[l]!=c[r])z+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
	}else{
		while(l!=r){
			if(a[l]==a[r]){
				if(c[l]!=c[r])z+=a[l];
				if(abs(r-l)==1)break;
				l++;
				r--;
			}else if(a[l]>a[r]){
				if(c[l]!=c[r])z+=a[r];
				a[l]-=a[r];
				r--;
			}else{
				if(c[l]!=c[r])z+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<z;
	return 0;
}
