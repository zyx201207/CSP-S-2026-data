#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int arr[n+5];
	char brr[n+5];
	for(int i=0;i<n;i++){
		cin>>arr[i]>>brr[i];
	}
	string m;
	int js=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<arr[i];j++){
			m[js]=brr[i];
			js++;
		}
	}
	string a,b;
	int js1=0;
	for(int i=0;i<js;i++){
		a[i]=m[i];
	}
	for(int i=js-1;i>=0;i--){
		b[js1]=m[i];
		js1++;
	}
	int h=0;
	for(int i=0;i<js;i++){
		if(a[i]!=b[i]){
			h++;	
		}
	}
	cout<<h/2;
	return 0;
}
