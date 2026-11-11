#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[1000000],o=0,j=1;
	char b[1000000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>b[i];
		
	}
	int i=0;
	while(i!=j){
		if(b[i]==b[n-j]){
			if(a[i]>a[n-j]){
				a[i]=a[i]-a[n-j];
				j++;
			}
			else if(a[i]<a[n-j]){
				a[n-j]=a[n-j]-a[i];
				i++;
			}
			else{
				i++;
				j++;
			}
			
		}
		if(b[i]!=b[n-j]){
			if(a[i]>a[n-j]){
				a[i]=a[i]-a[n-j];
				o+=a[n-j];
				j++;
			}
			else if(a[i]<a[n-j]){
				a[n-j]=a[n-j]-a[i];
				o+=a[i];
				i++;
				
				
			}
			else{
				o+=a[i];
				i++;
				j++;
			}
		}
	}
	cout<<o;
	return 0;

	
	
}
