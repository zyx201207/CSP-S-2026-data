#include<bits/stdc++.h>
using namespace std;
int a[2005];
char b[2005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];	
	}	
	if(n==1){
		cout<<"0";
	}
	else if(n==2){
		if(b[1]==b[2]){
			cout<<"0";
		}
		else{
			if(a[1]%2==0&&a[2]%2==0){
				if(a[1]>a[2]){
					cout<<a[2];
				}
				else if(a[1]==a[2]){
					cout<<"0";
				}
				else{
					cout<<a[1];
				}
			}
			if(a[1]%2==1){
				if(b[(a[1]+a[2])/2+1]==b[1]){
					cout<<a[1]/2;
				}
				else{
					cout<<a[1]/2+1;
				}
			}
			else if(a[2]%2==1){
				if(b[(a[1]+a[2])/2+1]==b[2]){
					cout<<a[2]/2;
				}
				else{
					cout<<a[2]/2+1;
				}
			}
		}
	}
	else{
		cout<<"0";
	}
	return 0;
} 
