#include<bits/stdc++.h>
using namespace std;
long long a[200007];
char b[200007];
int main(){
	freopen("string6.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n=0;
	cin>>n;
	long long x=0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		x+=a[i];
	}
	x/=2;
	long long m=0,k=0;
	while(true){
		if(m+a[k]<=x){
			m+=a[k];
			k++;
		}else{
			break;
		}
	}
	long long l=0,r=n-1,p=0;
	if(m!=x){
		p=x-m;
	}
	long long ans=0;
	while(1){
		if(l>=r){
			break;
		}
		if(l==k){
			a[l]=p;
		}
		if(b[l]!=b[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				ans+=a[r];
				r--;
		}else if(a[l]<a[r]){
				a[r]-=a[l];
				ans+=a[l];
				l++;
			}else{
				ans+=a[l];
				l++;
				r--;
			}
		}else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else{
				l++;
				r--;
			}
		}
		cout<<"";
	}
	cout<<ans;
}
       