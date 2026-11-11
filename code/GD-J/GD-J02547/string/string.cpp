#include<bits/stdc++.h>
using namespace std;
char b[200100],c;
long long t,n,sum1,sum2,sum3,l,r,z,a[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	r=t-1;
	for(int i=0;i<t;i++){
		cin>>n>>c;
		a[i]=n;
		b[i]=c;
		z+=n;
	}
	z/=2;
	for(int i=0;i<t;i++){
		sum1+=a[i];
		if(sum1>z){
			sum2=i;
			break;
		}
	}
	while(l<=r){
		if(b[l]==b[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else{
				a[r]-=a[l];
				l++;
			}
		}
		else if(b[l]!=b[r]){
			if(a[l]>a[r]){
				sum3+=a[r];
				a[l]-=a[r];
				r--;
			}
			else{
				sum3+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
		if(l==sum2||r==sum2) break;
	}
	if(r==sum2&&b[r]!=b[l]){
		sum3+=a[l];
	}
	else if(l==sum2&&b[r]!=b[l]){
		sum3+=a[r];
	}
	cout<<sum3;
}
