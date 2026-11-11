#include<bits/stdc++.h> 
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n,cha=0,he=0,l;
int a[20005];
char b[20005];
cin>>n;
for(int i=0;i<n;i++){
	cin>>a[i]>>b[i];
} 

	
for(int i=0;i<(n-1)/2+1;i++){
	if(cha!=0){
		if(l==0) {
			if(cha<=a[i]){
				l=1;
			}
			cha=max(cha,a[i])-min(cha,a[i]);
			he=he+cha;
			
		}
		if(l=1){
			if(cha>=a[i]){
				l=0;
			}
			
			cha=max(cha,a[i])-min(cha,a[i]);
			
			he=he+cha;
		}
	}
	else{
			cha=max(a[i],a[n-i-1])-min(a[i],a[n-i-1]);
		he=he+cha;
	if(a[i]>a[n-i]){
		l=0;
	}
	else{
		l=1;
	}
}}
cout<<he-1;
	return 0; 
}
