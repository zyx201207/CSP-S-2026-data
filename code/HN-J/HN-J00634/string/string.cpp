#include<iostream>
#include<cmath>
using namespace std;
int n,s,l;
int a[1000];
char c[1000];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	freopen("string.in",'r',stdin);
	freopen("string.out",'w',stdout);
	for(int i=0;i<=n/2;i++){
		if(c[i]!=c[n-1-i]){
			if(a[i]-a[n-1-i]>=0){
				l+=1;
				s+=a[n-1-i];
				a[i]-=a[n-1-i];
				for(int j=n-i-1-l;j>=0;j--){
					a[j+1]=a[j];
					c[j+1]=c[j]; 
				}
			}
			if(a[i]-a[n-1-i]<0){
				l-=1;
				s+=a[i];
				a[n-1-i]-=a[i];
				for(int k=l;k<=n-1;k++){
					a[k-1]=a[k];
					c[k-1]=c[k]; 
					
				}
			}
			
		}
		 
	}
	cout<<s;
	return 0;
}
