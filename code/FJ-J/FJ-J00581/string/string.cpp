#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a[200050]={},a1[200050]={},b=1,b1=1;
	long long s=0;
	char c[200050]={},c1[200050]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a1[n-i+1]=a[i];
		cin>>c[i];
		c1[n-i+1]=c[i];
	}
	for(long long i=1;i<=2*n;i++){
		if(c[b]==c1[b1]){
			if(a[b]>a1[b1]){
				a[b]-=a1[b1];
				a1[b1]=0;
				b1++;
			}else if(a1[b1]>a[b]){
				a1[b1]-=a[b];
				a[b]=0;
				b++;
			}else{
				a1[b1]=0;
				a[b]=0;
				b1++;
				b++;
			}
		}else{
			if(a[b]>a1[b1]){
				a[b]-=a1[b1];
				a1[b1]=0;
				b1++;
				s+=a[b];
			}else if(a1[b1]>a[b]){
				a1[b1]-=a[b];
				a[b]=0;
				b++;
				s+=a1[b1];
			}else{
				s+=a[b];
				a1[b1]=0;
				a[b]=0;
				b1++;
				b++;
			}
		}
	}
	cout<<s/2;
}
