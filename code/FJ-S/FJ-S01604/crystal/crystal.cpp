#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m,s=0,s1=0,z=0;
cin>>n>>m;
int a[n];
for(int i=1;i<=n;i++){
	cin>>a[i];
}
sort(a,a+n);
for(int i=1;i<=n;i++){
	if(n%2==0){
	if(i==n/2){
		z=a[i-1];
	}

if(a[i]==z&&i<n/2){
	s++;
}
if(a[i]>z){
		if(m>=0){
			
			m=m-(a[i]-z);
			if(m<0){
				break;
			}	
			s++;
			}
			else{
				break;
			}
}}
	if(n%2!=0){
	if(i*2+1==n){
		z=a[i];
	}

if(a[i]==z&&i<=n/2){
	s++;
}
if(a[i]>z){
		if(m>=0){
			m=m-(a[i]-z);
			if(m<0){
				break;
			}	
			s++;
			}
			else{
				break;
			}
}}
}
for(int i=n;i>=0;i--){
	if(a[i]<0){
				a[i]=-a[i];
			}
	if(n%2==0){
	if(i==n/2){
		z=a[i-1];
	}
if(a[i]==z&&i>n/2){
	s1++;
}
if(a[i]<z){
		if(m>=0){
			m=m-(z-a[i]);
			if(m<0){
				break;
			}	
			s1++;
			}
			else{
				break;
			}
}}
	if(n%2!=0){
	if(i*2+1==n){
		z=a[i];
	}

if(a[i]==z&&i>=n/2){
	s1++;
}
if(a[i]<z){
		if(m>=0){
			m=m-(z-a[i]);
			if(m<0){
				break;
			}	
			s1++;
			}
			else{
				break;
			}
}}
}
cout<<s<<" "<<s1;
if(s1>=s){
	cout<<s1;
}
else{
	cout<<s;
}
	return 0;
} 
