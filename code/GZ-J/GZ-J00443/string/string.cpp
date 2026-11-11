//GZ-J00443 兴义市弘毅中学 黄昌乾 
#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],i=0,s=0,l=0,num=0,k=1,m=0;
char c[200005],p;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(i=0;i<n;i++){
	cin>>a[i]>>c[i];
	s=s+a[i];
}
for(i=1;i<n;i++){
if(c[i]==c[i-1]){
	k++;
}
}
if(k==n){
	cout<<0;
}
for(i=0;i<n;i++){
	l=l+a[i];
	if(s%2!=0&&l>=s/2){
   a[i]--;
   break;
	}
}
for(i=0;i<n-1;i++){
if(a[i]>a[i+1]){
	c[i]=c[i+1];
}		
}
if(s%2!=0&&l>=s/2&&k!=n){
  sort(a,a+n);
for(i=0;i<n-1;i++){
	if(c[i]!=c[n-1]){
	num=num+a[i];	
	}
	
}
cout<<num;
	}
if(s%2==0&&l>=s/2&&k!=n){
	sort(a,a+n);
	for(i=0;i<n-1;i++){
	if(c[i]!=c[n-1]){
	num=num+a[i];	
	}
}
cout<<num;
	}






	return 0;
} 
